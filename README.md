# mere-config-lite
`mere-config-lite` derived from `mere-config` to make a very simple and lightweight configuration library for applications, where there is no need of heavyweight configuration management system.

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
  though its bit vervose.
  
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
  [Panel]
  background=red
  [Panel/Left]
  width=100px
  ```
**cross key-value pair**
  ```
  in this flexible format, pairs may, but need not, grouped using group name;
  
  Example: config.ini
  name=config-lite
  note=a simple library to work with configuration file
  [Panel]
  type=float
  width=200px
  height=auto
  ```

*note* - write operations yet to supported!
### Parser
**kvparser**
```
KVParser

Configurations that only contain key-value paiars are parsed with KVParser; Base api of this parser
returns list of all the valid properties;

Signature:
virtual std::vector<Property *> parse() const= 0;

You can define the pattern of the property, and key-value delimiter.
```
**gkparser**
```
GKParser - groupped key parser

Configurations that only contain groupped (named) key-value paiars are parsed with GKParser; Base 
api of this parser returns list of all the valid groups;

Signature:
virtual std::vector<Group *> parse() const= 0;

In addition of defining the pattern of the property, and key-value delimiter, you can define the 
pattern of the group and group delimiter - group delimiter is used to define the sub-group of a
group.
```
**ckparser**
```
CKParser - cross key parser

Configurations that may contain properties as well as groupped properties are parsed with CKParser; 
Base  api of this parser returns a root group;

Signature:
virtual Group * parse() const= 0;
```
### APIs
A simple set of apis to read and write configuration files(see *note* above). 
We need four apis, get/set and read/write, are quite enogh for most of the cases; most of the simple 
applications actually confiuration properties values - in that case get and read are fine.
```
- std::string get(const std::string &key) 
  to read property from already loaded configuration; 
- std::string read(const std::string &key)
  to read value of the poperty from the presistance system;

to indicate property of a group use flatten fully qualified key name - ie. window/height saying height
of the window.
```
