# How to use

## 0. How to set environment

Copy LMT folder to catkin_ws.

## 1. Make new project(package)

Put your package name instead of ${package_name}.

    catkin_create_pkg ${package_name} roscpp std_msgs geometry_msgs bebop_msgs nav_msgs

## 2. Copy files from a17_empty project

You have to copy these 5 files.

- CMakeLists.txt
- src/main.cpp
- src/CustomMissionHandler.h
- src/CustomMissionHandler.cpp

## 3. Modify CMakeLists.txt

- line 2: set proper project name

## 4. Customize CustomMissionHandler.cpp file

Change "a17_empty_node" to your proper node name in the constructor.

```
CustomMissionHandler::CustomMissionHandler(int argc, char** argv, int* pCommand)
: MissionHandler(argc, argv, "a17_empty_node", pCommand) {
    // initializing drone code here...
}
```

Now customize constructor and processCommand function.

## 5. Customize CustomCoreMission or CustomConcreteMission class

If you'd like to control only 1 drone, use CustomCoreMission. Or, if you want to control multiple drone, use CustomConcreteMission. Else, you can use both, to adopd CustomCoreMission as module of CustomConcreteMission.

- Compose perform function.
- Add class member as you wish.
- If you want, you can compose callback function executed in drone (ex. callWhenPositionChanged).


## 6. Reference

a18_go_up project is the sample, check it.

If you want more example,  a16_missionhandler_test.
