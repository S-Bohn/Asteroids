# Shader sources
list(APPEND SRC_SHADER
	Shader/Globals.h
	Shader/Manager.h
	Shader/Program.cpp
	Shader/Program.h
	Shader/Shader.h
	Shader/Shader.cpp
	Shader/UniformAssigner.h
	Shader/UniformAssigner.cpp 
)
SOURCE_GROUP("Shader" FILES ${SRC_SHADER})

# Geometry sources
list(APPEND SRC_GEOMETRY
	Geometry/Mesh.h
	Geometry/Mesh.cpp
)
SOURCE_GROUP("Geometry" FILES ${SRC_GEOMETRY})

# Window sources
list(APPEND SRC_WINDOW
	Window/Window.h
	Window/Window.cpp
)
SOURCE_GROUP("Window" FILES ${SRC_WINDOW})

# Game sources
list(APPEND SRC_GAME
	Game/Asteroid.h
	Game/Asteroid.cpp
	Game/ColliderComponent.h
	Game/ColliderComponent.cpp
	Game/FontRenderer.h
	Game/FontRenderer.cpp
	Game/Game.h
	Game/Game.cpp
	Game/GameObject.h
	Game/GameObject.cpp
	Game/ParticleEmitter.h
	Game/ParticleEmitter.cpp
	Game/PhysicsComponent.h
	Game/PhysicsComponent.cpp
	Game/Projectile.h
	Game/Projectile.cpp
	Game/Ship.h
	Game/Ship.cpp
)
SOURCE_GROUP("Game" FILES ${SRC_GAME})

# Source files
list(APPEND SRC_SOURCE
	main.cpp
)
SOURCE_GROUP("Source" FILES ${SRC_SOURCE})

list(APPEND SOURCES ${SRC_SHADER} ${SRC_GEOMETRY} ${SRC_WINDOW} ${SRC_GAME} ${SRC_SOURCE})

add_definitions("-DGLEW_STATIC -DGLM_FORCE_RADIANS")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} ${GLFW3_LIBRARY} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})