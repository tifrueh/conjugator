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

# Configure config.h on anything except macOS.
if host_machine.system() != 'darwin'

  configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: conf_data
  )

endif
