set(sources
    # Components
    src/Game/Components/PlayfieldComponent.cpp
    src/Game/Components/MarkerControllerComponent.cpp
    # Gameplay classes
    src/Game/Tile.cpp
    src/Game/Plot.cpp
    src/Game/Playfield.cpp
    src/Game/ExpansionMarker.cpp
    src/Game/MarkerController.cpp
    # src/Game/Location.cpp
    # Game states
    src/GameState/Views/GameView.cpp
    src/GameState/Views/GVMainMenu.cpp
    src/GameState/Views/GVDuel.cpp
    src/GameState/Controllers/GameController.cpp
    src/GameState/Controllers/GCMainMenu.cpp
    src/GameState/Controllers/GCDuel.cpp
    # GUI
    # src/GUI/ExpansionInterface.cpp
    src/GUI/ExpansionWindow.cpp
    # Game systems
    src/Resource/ResourceManager.cpp
)

set(exe_sources
        src/main.cpp
        ${sources}
)

set(headers
    # Components
    include/Game/Components/ImmobileComponent.hpp
    include/Game/Components/PositionComponent.hpp
    include/Game/Components/TextureContainerComponent.hpp
    include/Game/Components/SpriteComponent.hpp
    include/Game/Components/PlayfieldComponent.hpp
    include/Game/Components/PlotComponent.hpp
    include/Game/Components/EffectiveInteractionAreaComponent.hpp
    include/Game/Components/SelectableComponent.hpp
    include/Game/Components/SignalComponent.hpp
    include/Game/Components/ExpansionMarkerComponent.hpp
    include/Game/Components/MarkerControllerComponent.hpp
    # Gameplay classes
    include/Game/Tile.hpp
    include/Game/Plot.hpp
    include/Game/Playfield.hpp
    include/Game/Signal.hpp
    include/Game/ExpansionMarker.hpp
    include/Game/MarkerController.hpp
    # include/Game/Location.hpp
    # Game states
    include/GameState/Model/Common.hpp
    include/GameState/Model/Model.hpp
    include/GameState/Model/NoModel.hpp
    include/GameState/Views/GameView.hpp
    include/GameState/Views/GVFinal.hpp
    include/GameState/Views/GVMainMenu.hpp
    include/GameState/Views/GVDuel.hpp
    include/GameState/Controllers/GameController.hpp
    include/GameState/Controllers/GCFinal.hpp
    include/GameState/Controllers/GCMainMenu.hpp
    include/GameState/Controllers/GCDuel.hpp
    # GUI
    include/GUI/ExpansionInterface.hpp
    include/GUI/ExpansionWindow.hpp
    # Misc
    include/Misc/RangeWrapper.hpp
    include/Misc/PtrView.hpp
    include/Misc/EnumMap.hpp
    include/Misc/UID.hpp
    # Game systems
    include/ECS/ComponentContainer.hpp
    include/ECS/Entity.hpp
    include/AppState/AppState.hpp
    include/AppState/AppStateDefs.hpp
    include/AppState/StateIds.hpp
    include/AppState/Transitions.hpp
    include/Resource/ResourceManager.hpp
    include/Resource/IResourceManager.hpp
    include/GameWindow.hpp
    include/Renderer.hpp
    include/IApplication.hpp
    include/Application.hpp
)

set(test_sources
    # GUI
    src/GUI/ExpansionWindowTests.cpp
    # Misc
    src/Misc/PtrViewTests.cpp
    src/Misc/RangeWrapperTests.cpp
    src/Misc/EnumMapTests.cpp
    src/Misc/UIDTests.cpp
    # Game systems
    src/ApplicationTests.cpp
    # Components
    src/Game/Components/PlotComponentTests.cpp
    src/Game/Components/PlayfieldComponentTests.cpp
    src/Game/Components/EffectiveInteractionAreaComponentTests.cpp
    src/Game/Components/SelectableComponentTests.cpp
    src/Game/Components/SignalComponentTests.cpp
    src/Game/Components/ExpansionMarkerComponentTests.cpp
    src/Game/Components/MarkerControllerComponentTests.cpp
    # Gameplay classes
    src/RendererTests.cpp
    src/Game/TileTests.cpp
    src/Game/PlotTests.cpp
    src/Game/PlayfieldTests.cpp
    src/Game/ExpansionMarkerTests.cpp
)
