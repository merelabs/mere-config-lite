# mere-config-lite
`mere-config-lite` derived from `mere-config` to make a very simple and light weight configuration library for applications, where there is no need of heavyweight configuration management system.

`mere-config-lite` is currently suporting reading configuration files of following characteristics:

**key-value pair**
  ```
  simple, easy and convenient way of writing configuration. does not support any grouping.
  
  Example: config.conf
  name=config-lite
  note=a simple library to work with configuration file
  ```
**dotted key-value pair**
  ```
  another simple and easy way of writing configurations or properties with grouping facilities - 
  where propeties are groupped using dot notation; its very convenient way of writing properties
  though its bit more vervose.
  
  Example: config.dot
  mere.config.name=config-lite
  mere.config.note=a simple library to work with configuration file
  ```
**group wise key-value pair**
  ```
  pairs are groups using group or section name that appears on a line by itself in square brakets
  
  Example: config.ini
  [General]
  name=config-lite
  note=a simple library to work with configuration file
  
  ```
*note* - write operations yet to supported!
