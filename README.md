# Drone_PID

An Arduino PID Library used in Automated Flight Drone Project for Phys 124 at UCSD, Fall 2018.
Written by Michael Lazernik and Dillon Haughton.

## Contents

1. [Installing The Library](#installing-the-library)
   * [Linux](#linux)
     * [Command Line](#command-line)
     * [Download Zip](#download-zip)
   * [Mac](#mac)
   * [Windows](#windows)
1. [Using The Library](#using-the-library)
   * [Library Functions](#library-functions)
   * [Library Variables](#library-variables)

## Installing The Library

### Linux

#### Command Line

1. Locate your Sketchbook Directory and the libraries Directory Inside
   * Usually your sketchbook is located in your home directory and called either Arduino or Sketchbook.
  
   * To find you sketchbook open the Arduino IDE, click File, then Preferences. On the Settings tab you should see your Sketchbook location.
  
   * Your sketchbook directory should have a libraries Directory inside. If not, make one. Note the path to the libraries Directory, i.e.:
     ```
     ~/Arduino/libraries
     ```
     or
     ```
     /home/<user name>/Arduino/libraries
     ```
  
1. Navigate to you libraries directory in a terminal. i.e.:

   ```
   cd ~/Arduino/libraries
   ```

1. Clone the repository:

   ```
   git clone https://github.com/lazerj7/Drone_PID
   ```

1. That's it! You should now have a directory callled Drone_PID in your libraries directory with all the library files inside.

#### Download Zip

1. Locate your Sketchbook Directory and the libraries Directory Inside
   * Usually your sketchbook is located in your home directory and called either Arduino or Sketchbook.
  
   * To find you sketchbook open the Arduino IDE, click File, then Preferences. On the Settings tab you should see your Sketchbook location.
  
   * Your sketchbook directory should have a libraries Directory inside. If not, make one. Note the path to the libraries Directory.
  
1. In the upper right of the repository screen on GitHub, click 'Clone or Download', and then click 'Download ZIP'

1. Extract the .zip file into your libraries Directory.

1. Done!

### Mac

1. Locate your Sketchbook Directory and the libraries Directory Inside

   * Usually your sketchbook is located in your Documents directory and called Arduino. It should have a libraries Directory inside. If not, make one.

   * To find you sketchbook open the Arduino IDE, click File, then Preferences. On the Settings tab you should see your Sketchbook location.
  
   * Your sketchbook directory should have a libraries Directory inside. If not, make one. Note the path to the libraries Directory.
  
1. In the upper right of the repository screen on GitHub, click 'Clone or Download', and then click 'Download ZIP'

1. Extract the .zip file into your libraries Directory.

1. Done!

### Windows

1. Locate your Sketchbook Directory and the libraries Directory Inside

   * Usually your sketchbook is located in your Documents directory and called Arduino. It should have a libraries Directory inside. If not, make one.

   * To find you sketchbook open the Arduino IDE, click File, then Preferences. On the Settings tab you should see your Sketchbook location.
  
   * Your sketchbook directory should have a libraries Directory inside. If not, make one. Note the path to the libraries Directory.
  
1. In the upper right of the repository screen on GitHub, click 'Clone or Download', and then click 'Download ZIP'

1. Extract the .zip file into your libraries Directory.

1. Done!

## Using The Library

### Library Functions

  * ```cpp
    PID <name>(double kP, double kI, double kD, double input_minimum, double input_maximum);
    ``` 
    Creates a PID instance. <name> is the name of the variable you will use to refer to the new instance.
    * Parameters
      * ```cpp
        double kP
        ```
          Proportional Gain Coefficient
      * ```cpp
        double kI
        ```
          Integral Gain Coefficient
      * ```cpp
        double kD
        ```
          Derivative Gain Coefficient
      * ```cpp
        double input_minimum
        ```
          Minimum input value. Used to convert input to a percentage for calculations.
      * ```cpp
        double input_maximum
        ```
          Maximum input value. Used to convert input to a percentage for calculations.
  <br/>
  <br/>
  
  * ```cpp
    double run(double input, double set_point, double output_minimum, double output_maximum);
    ```
    Runs PID calculation.
    * Parameters
      * ```cpp
        double input
        ```
          Input value for calculations.
      * ```cpp
        double set_point
        ```
          Set Point for the system.
      * ```cpp
        double output_minimum
        ```
          Minimum output value.
      * ```cpp
        double output maximum
        ```
          Maximum output value.
    * Returns: a double representing the output of the PID calculations.
 
### Library Variables

To access library variables use the dot notation. For example, if you instantiated the library with:
```cpp
PID pid_instance(1.0, 1.0, 1.0, 0.0, 100.0);
```
Then you access the KP variable with:
```cpp
pid_instance.KP = 2.0;
```

  * ```cpp
    double KP;
    ```
    Proportional gain coeffecient. The value of this variable may be modified after instantiation to change the gain coefficient.
  * ```cpp
    double KI;
    ```
    Integral gain coeffecient. The value of this variable may be modified after instantiation to change the gain coefficient.
  * ```cpp
    double KD;
    ```
    Derivative gain coeffecient. The value of this variable may be modified after instantiation to change the gain coefficient.
  * ```cpp
    double inputMax;
    ```
    Maximum input value. The value of this variable may be modified after instantion to change the maximum input value.
  * ```cpp
    double inputMin;
    ```
    Minimum input value. The value of this variable may be modified after instantion to change the minimum input value.
