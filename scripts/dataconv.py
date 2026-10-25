import argparse
import re
import sys
import tomllib

# = Globals ====================================================================

formats = ["oldfrverbcpp", "frverbcpp", "frtoml"]
oldfrverbcpp_rstr = r"""const verbDB::Verb verbDB::(?P<identifier>\w+) = {\s*L"(?P<label>[^"]*)",\s*verbDB::VerbType::(?P<group>\w+),\s*\s*L"(?P<infinitif>[^"]*)",\s*L"(?P<translation>[^"]*)",\s*L"(?P<participe_present>[^"]*)",\s*\s*L"(?P<present_je>[^"]*)",\s*L"(?P<present_tu>[^"]*)",\s*L"(?P<present_il>[^"]*)",\s*L"(?P<present_elle>[^"]*)",\s*L"(?P<present_nous>[^"]*)",\s*L"(?P<present_vous>[^"]*)",\s*L"(?P<present_ils>[^"]*)",\s*L"(?P<present_elles>[^"]*)",\s*\s*L"(?P<imparfait_je>[^"]*)",\s*L"(?P<imparfait_tu>[^"]*)",\s*L"(?P<imparfait_il>[^"]*)",\s*L"(?P<imparfait_elle>[^"]*)",\s*L"(?P<imparfait_nous>[^"]*)",\s*L"(?P<imparfait_vous>[^"]*)",\s*L"(?P<imparfait_ils>[^"]*)",\s*L"(?P<imparfait_elles>[^"]*)",\s*\s*L"(?P<futur_je>[^"]*)",\s*L"(?P<futur_tu>[^"]*)",\s*L"(?P<futur_il>[^"]*)",\s*L"(?P<futur_elle>[^"]*)",\s*L"(?P<futur_nous>[^"]*)",\s*L"(?P<futur_vous>[^"]*)",\s*L"(?P<futur_ils>[^"]*)",\s*L"(?P<futur_elles>[^"]*)",\s*\s*L"(?P<passe_compose_je>[^"]*)",\s*L"(?P<passe_compose_tu>[^"]*)",\s*L"(?P<passe_compose_il>[^"]*)",\s*L"(?P<passe_compose_elle>[^"]*)",\s*L"(?P<passe_compose_nous>[^"]*)",\s*L"(?P<passe_compose_vous>[^"]*)",\s*L"(?P<passe_compose_ils>[^"]*)",\s*L"(?P<passe_compose_elles>[^"]*)",\s*\s*L"(?P<plus_que_parfait_je>[^"]*)",\s*L"(?P<plus_que_parfait_tu>[^"]*)",\s*L"(?P<plus_que_parfait_il>[^"]*)",\s*L"(?P<plus_que_parfait_elle>[^"]*)",\s*L"(?P<plus_que_parfait_nous>[^"]*)",\s*L"(?P<plus_que_parfait_vous>[^"]*)",\s*L"(?P<plus_que_parfait_ils>[^"]*)",\s*L"(?P<plus_que_parfait_elles>[^"]*)",\s*\s*L"(?P<subjonctif_je>[^"]*)",\s*L"(?P<subjonctif_tu>[^"]*)",\s*L"(?P<subjonctif_il>[^"]*)",\s*L"(?P<subjonctif_elle>[^"]*)",\s*L"(?P<subjonctif_nous>[^"]*)",\s*L"(?P<subjonctif_vous>[^"]*)",\s*L"(?P<subjonctif_ils>[^"]*)",\s*L"(?P<subjonctif_elles>[^"]*)",\s*\s*L"(?P<conditionnel_je>[^"]*)",\s*L"(?P<conditionnel_tu>[^"]*)",\s*L"(?P<conditionnel_il>[^"]*)",\s*L"(?P<conditionnel_elle>[^"]*)",\s*L"(?P<conditionnel_nous>[^"]*)",\s*L"(?P<conditionnel_vous>[^"]*)",\s*L"(?P<conditionnel_ils>[^"]*)",\s*L"(?P<conditionnel_elles>[^"]*)"\s*};"""
frverbcpp_rstr = r"""const verbDB::Verb verbDB::(?P<identifier>\w+) = {\s*L"(?P<label>[^"]*)",\s*L"(?P<translation>[^"]*)",\s*{\s*L"(?P<infinitif>[^"]*)",\s*L"(?P<participe_present>[^"]*)",\s*\s*L"(?P<present_je>[^"]*)",\s*L"(?P<present_tu>[^"]*)",\s*L"(?P<present_il>[^"]*)",\s*L"(?P<present_elle>[^"]*)",\s*L"(?P<present_nous>[^"]*)",\s*L"(?P<present_vous>[^"]*)",\s*L"(?P<present_ils>[^"]*)",\s*L"(?P<present_elles>[^"]*)",\s*\s*L"(?P<imparfait_je>[^"]*)",\s*L"(?P<imparfait_tu>[^"]*)",\s*L"(?P<imparfait_il>[^"]*)",\s*L"(?P<imparfait_elle>[^"]*)",\s*L"(?P<imparfait_nous>[^"]*)",\s*L"(?P<imparfait_vous>[^"]*)",\s*L"(?P<imparfait_ils>[^"]*)",\s*L"(?P<imparfait_elles>[^"]*)",\s*\s*L"(?P<futur_je>[^"]*)",\s*L"(?P<futur_tu>[^"]*)",\s*L"(?P<futur_il>[^"]*)",\s*L"(?P<futur_elle>[^"]*)",\s*L"(?P<futur_nous>[^"]*)",\s*L"(?P<futur_vous>[^"]*)",\s*L"(?P<futur_ils>[^"]*)",\s*L"(?P<futur_elles>[^"]*)",\s*\s*L"(?P<passe_compose_je>[^"]*)",\s*L"(?P<passe_compose_tu>[^"]*)",\s*L"(?P<passe_compose_il>[^"]*)",\s*L"(?P<passe_compose_elle>[^"]*)",\s*L"(?P<passe_compose_nous>[^"]*)",\s*L"(?P<passe_compose_vous>[^"]*)",\s*L"(?P<passe_compose_ils>[^"]*)",\s*L"(?P<passe_compose_elles>[^"]*)",\s*\s*L"(?P<plus_que_parfait_je>[^"]*)",\s*L"(?P<plus_que_parfait_tu>[^"]*)",\s*L"(?P<plus_que_parfait_il>[^"]*)",\s*L"(?P<plus_que_parfait_elle>[^"]*)",\s*L"(?P<plus_que_parfait_nous>[^"]*)",\s*L"(?P<plus_que_parfait_vous>[^"]*)",\s*L"(?P<plus_que_parfait_ils>[^"]*)",\s*L"(?P<plus_que_parfait_elles>[^"]*)",\s*\s*L"(?P<subjonctif_je>[^"]*)",\s*L"(?P<subjonctif_tu>[^"]*)",\s*L"(?P<subjonctif_il>[^"]*)",\s*L"(?P<subjonctif_elle>[^"]*)",\s*L"(?P<subjonctif_nous>[^"]*)",\s*L"(?P<subjonctif_vous>[^"]*)",\s*L"(?P<subjonctif_ils>[^"]*)",\s*L"(?P<subjonctif_elles>[^"]*)",\s*\s*L"(?P<conditionnel_je>[^"]*)",\s*L"(?P<conditionnel_tu>[^"]*)",\s*L"(?P<conditionnel_il>[^"]*)",\s*L"(?P<conditionnel_elle>[^"]*)",\s*L"(?P<conditionnel_nous>[^"]*)",\s*L"(?P<conditionnel_vous>[^"]*)",\s*L"(?P<conditionnel_ils>[^"]*)",\s*L"(?P<conditionnel_elles>[^"]*)"\s*}\s*};"""
oldfrverbcpp_regex = re.compile(oldfrverbcpp_rstr)
frverbcpp_regex = re.compile(frverbcpp_rstr)

# = Intermediate Data Representation ===========================================


class VerbIR:

    uid = "uid"
    infinitive = "infinitive"
    language = "language"
    group = "group"

    translations = {"de": "german translation"}

    conjugations = {}

    def from_frverbcpp(self, frverbcpp):

        # Parse the input string.
        match = frverbcpp_regex.search(frverbcpp)
        if not match:
            print("error: failed to parse frverbcpp string")
            exit(1)

        # Populate self.
        self.from_regex_match(match)

    def from_oldfrverbcpp(self, oldfrverbcpp):

        # Parse the input string.
        match = oldfrverbcpp_regex.search(oldfrverbcpp)
        if not match:
            print("error: failed to parse frverbcpp string")
            exit(1)

        # Populate self.
        self.from_regex_match(match)

    def from_regex_match(self, match):
        self.uid = match.group("identifier")
        self.infinitive = match.group("infinitif")
        self.language = "fr"

        try:
            self.group = match.group("group")
        except IndexError:
            self.group = "none"

        self.translations = {"de": match.group("translation")}

        self.conjugations = {
            "participe_present": {"none": match.group("participe_present")},
            "present": {
                "je": match.group("present_je"),
                "tu": match.group("present_tu"),
                "il": match.group("present_il"),
                "elle": match.group("present_elle"),
                "nous": match.group("present_nous"),
                "vous": match.group("present_vous"),
                "ils": match.group("present_ils"),
                "elles": match.group("present_elles"),
            },
            "imparfait": {
                "je": match.group("imparfait_je"),
                "tu": match.group("imparfait_tu"),
                "il": match.group("imparfait_il"),
                "elle": match.group("imparfait_elle"),
                "nous": match.group("imparfait_nous"),
                "vous": match.group("imparfait_vous"),
                "ils": match.group("imparfait_ils"),
                "elles": match.group("imparfait_elles"),
            },
            "futur": {
                "je": match.group("futur_je"),
                "tu": match.group("futur_tu"),
                "il": match.group("futur_il"),
                "elle": match.group("futur_elle"),
                "nous": match.group("futur_nous"),
                "vous": match.group("futur_vous"),
                "ils": match.group("futur_ils"),
                "elles": match.group("futur_elles"),
            },
            "passe_compose": {
                "je": match.group("passe_compose_je"),
                "tu": match.group("passe_compose_tu"),
                "il": match.group("passe_compose_il"),
                "elle": match.group("passe_compose_elle"),
                "nous": match.group("passe_compose_nous"),
                "vous": match.group("passe_compose_vous"),
                "ils": match.group("passe_compose_ils"),
                "elles": match.group("passe_compose_elles"),
            },
            "plus_que_parfait": {
                "je": match.group("plus_que_parfait_je"),
                "tu": match.group("plus_que_parfait_tu"),
                "il": match.group("plus_que_parfait_il"),
                "elle": match.group("plus_que_parfait_elle"),
                "nous": match.group("plus_que_parfait_nous"),
                "vous": match.group("plus_que_parfait_vous"),
                "ils": match.group("plus_que_parfait_ils"),
                "elles": match.group("plus_que_parfait_elles"),
            },
            "subjonctif": {
                "je": match.group("subjonctif_je"),
                "tu": match.group("subjonctif_tu"),
                "il": match.group("subjonctif_il"),
                "elle": match.group("subjonctif_elle"),
                "nous": match.group("subjonctif_nous"),
                "vous": match.group("subjonctif_vous"),
                "ils": match.group("subjonctif_ils"),
                "elles": match.group("subjonctif_elles"),
            },
            "conditionnel": {
                "je": match.group("conditionnel_je"),
                "tu": match.group("conditionnel_tu"),
                "il": match.group("conditionnel_il"),
                "elle": match.group("conditionnel_elle"),
                "nous": match.group("conditionnel_nous"),
                "vous": match.group("conditionnel_vous"),
                "ils": match.group("conditionnel_ils"),
                "elles": match.group("conditionnel_elles"),
            },
        }

    def from_frtoml(self, frtoml):

        datadict = tomllib.loads(frtoml)

        self.uid = datadict["uid"]
        self.infinitive = datadict["infinitive"]
        self.language = datadict["language"]
        self.group = datadict["group"]

        self.translations = datadict["translations"]
        self.conjugations = datadict["conjugations"]

    def to_oldfrverbcpp(self):
        return f"""#include "verb.db.hpp"

const verbDB::Verb verbDB::{self.uid} = {{

    L"{self.infinitive}",

    verbDB::VerbType::{self.group}

    L"{self.infinitive}",
    L"{self.translations["de"]}",
    L"{self.conjugations["participe_present"]["none"]}",

    L"{self.conjugations["present"]["je"]}",
    L"{self.conjugations["present"]["tu"]}",
    L"{self.conjugations["present"]["il"]}",
    L"{self.conjugations["present"]["elle"]}",
    L"{self.conjugations["present"]["nous"]}",
    L"{self.conjugations["present"]["vous"]}",
    L"{self.conjugations["present"]["ils"]}",
    L"{self.conjugations["present"]["elles"]}",

    L"{self.conjugations["imparfait"]["je"]}",
    L"{self.conjugations["imparfait"]["tu"]}",
    L"{self.conjugations["imparfait"]["il"]}",
    L"{self.conjugations["imparfait"]["elle"]}",
    L"{self.conjugations["imparfait"]["nous"]}",
    L"{self.conjugations["imparfait"]["vous"]}",
    L"{self.conjugations["imparfait"]["ils"]}",
    L"{self.conjugations["imparfait"]["elles"]}",

    L"{self.conjugations["futur"]["je"]}",
    L"{self.conjugations["futur"]["tu"]}",
    L"{self.conjugations["futur"]["il"]}",
    L"{self.conjugations["futur"]["elle"]}",
    L"{self.conjugations["futur"]["nous"]}",
    L"{self.conjugations["futur"]["vous"]}",
    L"{self.conjugations["futur"]["ils"]}",
    L"{self.conjugations["futur"]["elles"]}",

    L"{self.conjugations["passe_compose"]["je"]}",
    L"{self.conjugations["passe_compose"]["tu"]}",
    L"{self.conjugations["passe_compose"]["il"]}",
    L"{self.conjugations["passe_compose"]["elle"]}",
    L"{self.conjugations["passe_compose"]["nous"]}",
    L"{self.conjugations["passe_compose"]["vous"]}",
    L"{self.conjugations["passe_compose"]["ils"]}",
    L"{self.conjugations["passe_compose"]["elles"]}",

    L"{self.conjugations["plus_que_parfait"]["je"]}",
    L"{self.conjugations["plus_que_parfait"]["tu"]}",
    L"{self.conjugations["plus_que_parfait"]["il"]}",
    L"{self.conjugations["plus_que_parfait"]["elle"]}",
    L"{self.conjugations["plus_que_parfait"]["nous"]}",
    L"{self.conjugations["plus_que_parfait"]["vous"]}",
    L"{self.conjugations["plus_que_parfait"]["ils"]}",
    L"{self.conjugations["plus_que_parfait"]["elles"]}",

    L"{self.conjugations["subjonctif"]["je"]}",
    L"{self.conjugations["subjonctif"]["tu"]}",
    L"{self.conjugations["subjonctif"]["il"]}",
    L"{self.conjugations["subjonctif"]["elle"]}",
    L"{self.conjugations["subjonctif"]["nous"]}",
    L"{self.conjugations["subjonctif"]["vous"]}",
    L"{self.conjugations["subjonctif"]["ils"]}",
    L"{self.conjugations["subjonctif"]["elles"]}",

    L"{self.conjugations["conditionnel"]["je"]}",
    L"{self.conjugations["conditionnel"]["tu"]}",
    L"{self.conjugations["conditionnel"]["il"]}",
    L"{self.conjugations["conditionnel"]["elle"]}",
    L"{self.conjugations["conditionnel"]["nous"]}",
    L"{self.conjugations["conditionnel"]["vous"]}",
    L"{self.conjugations["conditionnel"]["ils"]}",
    L"{self.conjugations["conditionnel"]["elles"]}"
}};
"""

    def to_frverbcpp(self):
        return f"""#include "verb.db.hpp"

const verbDB::Verb verbDB::{self.uid} = {{

    L"{self.infinitive}",
    L"{self.translations["de"]}",

    {{
        L"{self.infinitive}",
        L"{self.conjugations["participe_present"]["none"]}",

        L"{self.conjugations["present"]["je"]}",
        L"{self.conjugations["present"]["tu"]}",
        L"{self.conjugations["present"]["il"]}",
        L"{self.conjugations["present"]["elle"]}",
        L"{self.conjugations["present"]["nous"]}",
        L"{self.conjugations["present"]["vous"]}",
        L"{self.conjugations["present"]["ils"]}",
        L"{self.conjugations["present"]["elles"]}",

        L"{self.conjugations["imparfait"]["je"]}",
        L"{self.conjugations["imparfait"]["tu"]}",
        L"{self.conjugations["imparfait"]["il"]}",
        L"{self.conjugations["imparfait"]["elle"]}",
        L"{self.conjugations["imparfait"]["nous"]}",
        L"{self.conjugations["imparfait"]["vous"]}",
        L"{self.conjugations["imparfait"]["ils"]}",
        L"{self.conjugations["imparfait"]["elles"]}",

        L"{self.conjugations["futur"]["je"]}",
        L"{self.conjugations["futur"]["tu"]}",
        L"{self.conjugations["futur"]["il"]}",
        L"{self.conjugations["futur"]["elle"]}",
        L"{self.conjugations["futur"]["nous"]}",
        L"{self.conjugations["futur"]["vous"]}",
        L"{self.conjugations["futur"]["ils"]}",
        L"{self.conjugations["futur"]["elles"]}",

        L"{self.conjugations["passe_compose"]["je"]}",
        L"{self.conjugations["passe_compose"]["tu"]}",
        L"{self.conjugations["passe_compose"]["il"]}",
        L"{self.conjugations["passe_compose"]["elle"]}",
        L"{self.conjugations["passe_compose"]["nous"]}",
        L"{self.conjugations["passe_compose"]["vous"]}",
        L"{self.conjugations["passe_compose"]["ils"]}",
        L"{self.conjugations["passe_compose"]["elles"]}",

        L"{self.conjugations["plus_que_parfait"]["je"]}",
        L"{self.conjugations["plus_que_parfait"]["tu"]}",
        L"{self.conjugations["plus_que_parfait"]["il"]}",
        L"{self.conjugations["plus_que_parfait"]["elle"]}",
        L"{self.conjugations["plus_que_parfait"]["nous"]}",
        L"{self.conjugations["plus_que_parfait"]["vous"]}",
        L"{self.conjugations["plus_que_parfait"]["ils"]}",
        L"{self.conjugations["plus_que_parfait"]["elles"]}",

        L"{self.conjugations["subjonctif"]["je"]}",
        L"{self.conjugations["subjonctif"]["tu"]}",
        L"{self.conjugations["subjonctif"]["il"]}",
        L"{self.conjugations["subjonctif"]["elle"]}",
        L"{self.conjugations["subjonctif"]["nous"]}",
        L"{self.conjugations["subjonctif"]["vous"]}",
        L"{self.conjugations["subjonctif"]["ils"]}",
        L"{self.conjugations["subjonctif"]["elles"]}",

        L"{self.conjugations["conditionnel"]["je"]}",
        L"{self.conjugations["conditionnel"]["tu"]}",
        L"{self.conjugations["conditionnel"]["il"]}",
        L"{self.conjugations["conditionnel"]["elle"]}",
        L"{self.conjugations["conditionnel"]["nous"]}",
        L"{self.conjugations["conditionnel"]["vous"]}",
        L"{self.conjugations["conditionnel"]["ils"]}",
        L"{self.conjugations["conditionnel"]["elles"]}"
    }}
}};
"""

    def to_frtoml(self):
        return f"""# ==============================================================================
# {self.infinitive}
# ==============================================================================

# General verb metadata ========================================================

uid = "{self.uid}"
infinitive = "{self.infinitive}"
language = "{self.language}"
group = "{self.group}"

[translations]
de = "{self.translations["de"]}"

# Conjugations =================================================================

[conjugations.participe_present]
none = "{self.conjugations["participe_present"]["none"]}"

[conjugations.present]
je = "{self.conjugations["present"]["je"]}"
tu = "{self.conjugations["present"]["tu"]}"
il = "{self.conjugations["present"]["il"]}"
elle = "{self.conjugations["present"]["elle"]}"
nous = "{self.conjugations["present"]["nous"]}"
vous = "{self.conjugations["present"]["vous"]}"
ils = "{self.conjugations["present"]["ils"]}"
elles = "{self.conjugations["present"]["elles"]}"

[conjugations.imparfait]
je = "{self.conjugations["imparfait"]["je"]}"
tu = "{self.conjugations["imparfait"]["tu"]}"
il = "{self.conjugations["imparfait"]["il"]}"
elle = "{self.conjugations["imparfait"]["elle"]}"
nous = "{self.conjugations["imparfait"]["nous"]}"
vous = "{self.conjugations["imparfait"]["vous"]}"
ils = "{self.conjugations["imparfait"]["ils"]}"
elles = "{self.conjugations["imparfait"]["elles"]}"

[conjugations.futur]
je = "{self.conjugations["futur"]["je"]}"
tu = "{self.conjugations["futur"]["tu"]}"
il = "{self.conjugations["futur"]["il"]}"
elle = "{self.conjugations["futur"]["elle"]}"
nous = "{self.conjugations["futur"]["nous"]}"
vous = "{self.conjugations["futur"]["vous"]}"
ils = "{self.conjugations["futur"]["ils"]}"
elles = "{self.conjugations["futur"]["elles"]}"

[conjugations.passe_compose]
je = "{self.conjugations["passe_compose"]["je"]}"
tu = "{self.conjugations["passe_compose"]["tu"]}"
il = "{self.conjugations["passe_compose"]["il"]}"
elle = "{self.conjugations["passe_compose"]["elle"]}"
nous = "{self.conjugations["passe_compose"]["nous"]}"
vous = "{self.conjugations["passe_compose"]["vous"]}"
ils = "{self.conjugations["passe_compose"]["ils"]}"
elles = "{self.conjugations["passe_compose"]["elles"]}"

[conjugations.plus_que_parfait]
je = "{self.conjugations["plus_que_parfait"]["je"]}"
tu = "{self.conjugations["plus_que_parfait"]["tu"]}"
il = "{self.conjugations["plus_que_parfait"]["il"]}"
elle = "{self.conjugations["plus_que_parfait"]["elle"]}"
nous = "{self.conjugations["plus_que_parfait"]["nous"]}"
vous = "{self.conjugations["plus_que_parfait"]["vous"]}"
ils = "{self.conjugations["plus_que_parfait"]["ils"]}"
elles = "{self.conjugations["plus_que_parfait"]["elles"]}"

[conjugations.subjonctif]
je = "{self.conjugations["subjonctif"]["je"]}"
tu = "{self.conjugations["subjonctif"]["tu"]}"
il = "{self.conjugations["subjonctif"]["il"]}"
elle = "{self.conjugations["subjonctif"]["elle"]}"
nous = "{self.conjugations["subjonctif"]["nous"]}"
vous = "{self.conjugations["subjonctif"]["vous"]}"
ils = "{self.conjugations["subjonctif"]["ils"]}"
elles = "{self.conjugations["subjonctif"]["elles"]}"

[conjugations.conditionnel]
je = "{self.conjugations["conditionnel"]["je"]}"
tu = "{self.conjugations["conditionnel"]["tu"]}"
il = "{self.conjugations["conditionnel"]["il"]}"
elle = "{self.conjugations["conditionnel"]["elle"]}"
nous = "{self.conjugations["conditionnel"]["nous"]}"
vous = "{self.conjugations["conditionnel"]["vous"]}"
ils = "{self.conjugations["conditionnel"]["ils"]}"
elles = "{self.conjugations["conditionnel"]["elles"]}"
"""


# = Main Script ================================================================

# Setup CLI parsing.

parser = argparse.ArgumentParser(
    prog="dataconv.py",
    description="Tool for converting to and from various verb formats",
    epilog="Note that this tool only handles French verbs correctly at the \
    moment, as those are the only ones that are in use.",
)

parser.add_argument(
    "-f", "--format", choices=formats, help="format to convert from", required=True
)
parser.add_argument(
    "-t", "--to", choices=formats, help="format to convert to", required=True
)
parser.add_argument(
    "file", help="path to the file to be used as input (- for stdin)"
)
parser.add_argument(
    "-o",
    "--output",
    help="path to the file to be used as output (stdout by default)",
    required=False,
    default="-"
)

args = parser.parse_args()

# Decide what to do based on the arguments.

if args.file == "-":
    input_file = sys.stdin
else:
    input_file = open(args.file, "r")

if (not args.output) or args.output == "-":
    output_file = sys.stdout
else:
    output_file = open(args.output, "w")

input = input_file.read()
input_file.close()

verb = VerbIR()

if args.format == "oldfrverbcpp":
    verb.from_oldfrverbcpp(input)
elif args.format == "frverbcpp":
    verb.from_frverbcpp(input)
elif args.format == "frtoml":
    verb.from_frtoml(input)
else:
    print("this conversion is not yet implemented")
    exit(1)

if args.to == "frtoml":
    result = verb.to_frtoml()
elif args.to == "oldfrverbcpp":
    result = verb.to_oldfrverbcpp()
elif args.to == "frverbcpp":
    result = verb.to_frverbcpp()
else:
    print("this conversion is not yet implemented")
    exit(1)

output_file.write(result)
output_file.close()
