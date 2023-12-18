if host_machine.system() == 'darwin'
  
  configure_file(
    input: 'Info.plist.in',
    output: 'Info.plist',
    configuration: conf_data
  )

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

if host_machine.system() != 'darwin'

  configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: conf_data
  )

endif
