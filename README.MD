### Creating project, initial commit with GitLFS ###

+ UnrealFPS will be multiplayer survival(?) game
+ Players will have possibility to work together to accomplish objective


### Added Third Person Mesh ###

+ Prepairing for implementing basic AI

### AI patrolling (behaviour tree) ###

+ AI moving through patrol points

### AI patrolling implemented in C++ ###

+ ChooseNextWaypoint class is now responsible for setting next waypoint
+ PatrolRoute contains pointer to TargetPoints Array in game

### Added AI Perception ###

+ NPCs are now able to see and hear 

### Refactoring ###

+ Improved folder structure in Unreal
+ Improved naming and folder structure in C++ source folder
+ Removed VR staff from FirstPersonCharacter class