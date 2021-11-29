#ifndef APPSTATEDEFS_HPP_
#define APPSTATEDEFS_HPP_

class GSFinal;
class UISFinal;
class GSMainMenu;
class UISMainMenu;
class GSDuelHotSeat;
class UISDuelHotSeat;

// Helper struct and typedefs that store valid (GameState, UiState) pairs
namespace AppStateDefs
{
    namespace
    {
        template <class TGameState, class TUiState>
        struct StatePair final {
            using gs_type = TGameState;
            using ui_type = TUiState;
        };
    }

    using FinalState = StatePair<GSFinal, UISFinal>;
    using MainMenuState = StatePair<GSMainMenu, UISMainMenu>;
    using DuelHotSeatState = StatePair<GSDuelHotSeat, UISDuelHotSeat>;
};

#endif // APPSTATEDEFS_HPP_