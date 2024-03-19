# Configure Info.plist if on macOS.
if host_machine.system() == 'darwin'
  
  configure_file(
    input: 'Info.plist.in',
    output: 'Info.plist',
    configuration: conf_data
  )

# Configure resources.rc and conjugateur.iss on Windows.
elif host_machine.system() == 'windows' 
  
  configure_file(
    input: 'resources.rc.in',
    output: 'resources.rc',
    configuration: conf_data
  )

  configure_file(
    input: 'conjugateur.iss.in',
    output: 'conjugateur.iss',
    configuration: conf_data
  )

endif

# Always configure config.hpp.
configure_file(
  input: 'config.hpp.in',
  output: 'config.hpp',
  configuration: conf_data
)
