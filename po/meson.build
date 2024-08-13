# Import the i18n module.
i18n = import('i18n')

add_project_arguments('-DGETTEXT_PACKAGE="intltest"', language:'cpp')

gettext_return = i18n.gettext(
  meson.project_name(),
  args: [ '--from-code=utf-8', '-k_' ],
  install: true
)
