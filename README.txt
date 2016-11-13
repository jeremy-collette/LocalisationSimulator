LOCALISATION SIMULATOR
Copyright (C) 2016 Jeremy Collette.
=================================================

INTRODUCTION
-------------------
LocalisationSimulator was written for a university project. The program simulates the use of a Kalman Filter for robot localisation on a 2D soccer field. The aim of this project was to learn how a Kalman Filter works, and apply it to an example in the RoboCup domain. 

LocalisationSimulator displays an image of a soccer field, with a simulated robot represented by a black circle. Robot estimators are represented by circles of other colours, and are used to estimate the position of the robot, given noisy position and velocity data at regular intervals. The Kalman Filter is one of these robot estimators, and the purpose of LocalisationSimulator is to compare its performance with other, very simple, robot estimators.


ACKNOWLEDGEMENTS
-------------------
LocalisationSimulator is made using Eigen (http://eigen.tuxfamily.org) and SFML (https://www.sfml-dev.org/). Both of these libraries are not my original work and are unmodified in their entirity in this distribution. Thanks developers! A shoutout to SFML for having such a friendly license (the zlib/png license).

LocalisationSimulator also uses the font Gravity by Vincenzo Vuono (http://vincenzovuono.com). The font has remained unmodified and is protected by copyright (C) laws. Cheers Vince!


PLATFORMS
-------------------
LocalisationSimulator is currently only supported on Windows.


RUNNING
-------------------
If you simply want to run the LocalisationSimulator, then download a release (https://github.com/jezdawgz/LocalisationSimulator/releases) and run 'LocalisationSimulator.exe' in the 'bin' folder. Be sure to run the executable from a terminal, as commandline arguments are required for configuration. Run 'LocalisationSimulator.exe' without any arguments to see usage information.


BUILDING
-------------------
If you want to build LocalisationSimulator from source, simply open 'vs2013/LocalisationSimulator.sln' in Visual Studio 2013. Later versions may be able to open the solution file, but they are not supported.


LICENSE
-------------------
See 'LICENSE.txt' for licensing information.
