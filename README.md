# 6-Axis Robot Arm Kinematics: Inverse and Forward Calculations

## Description

This project encompasses a C program that performs kinematic calculations for a 6-axis robot arm. Forward kinematics calculations are achieved using Denavit-Hartenberg (DH) parameters, while inverse kinematics calculations aim to determine the joint angles for the robot arm to reach a specific position and orientation.

### Forward Kinematics:

- Computes the position and orientation of the robot arm using DH parameters.
- Forward kinematics calculations are executed by the `forwardKinematics` function.
- Utilizes an example set of DH parameters to predict the robot's position and orientation in a specific scenario.

### Inverse Kinematics:

- Aims to calculate the joint angles of the robot arm by specifying a target position and orientation.
- Inverse kinematics calculations are outlined in a general structure within the `inverseKinematics` function.
- For a real robot, this function should be adapted to the robot's kinematic model and specific requirements.

### Technologies and Tools:

- Implemented in the C programming language.
- Kinematic calculations performed using Denavit-Hartenberg parameters.

## How to Use

1. Clone the project to your computer.
2. Understand the robot's position and orientation calculations by reviewing the `forwardKinematics` and `inverseKinematics` functions.
3. Customize the project by using your own DH parameters and target position/orientation values.
4. Compile and run the C code to observe the results.

### Notes

- Both forward and inverse kinematic calculations are designed for a general 6-axis robot arm.
- For a real robot, kinematic models and calculation algorithms should be specifically tailored.

This project is created to provide a foundational understanding of 6-axis robot arm kinematics.
