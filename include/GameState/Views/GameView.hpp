// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
// OpenLabora (c) by Flotsamarch (https://github.com/flotsamarch)
//
// This work is licensed under the Creative Commons
// Attribution-NonCommercial-ShareAlike 4.0 International License.
//
// You should have received a copy of the license along with this
// work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.
//
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#ifndef GAMEVIEW_HPP_
#define GAMEVIEW_HPP_

#include <memory>
#include <vector>
#include <TGUI/Core.hpp>
#include <TGUI/Backends/SFML.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>
#include "GameWindow.hpp"
#include "GameState/Controllers/GameController.hpp"
#include "IApplication.hpp"
#include "AppState/StateIds.hpp"
#include "GUI/ExpansionInterface.hpp"

namespace OpenLabora
{

// General gameplay UI logic base class
class GameView
{
protected:
    using VBox = tgui::VerticalLayout;

    PtrView<IApplication<StateIdsVariant>> mApp;
    GameWindow<tgui::GuiSFML, sf::RenderWindow> mWindow;
    GameController::Ptr mController;
    Model::PtrConst mModel;

    sf::Vector2i mMouseCoords;
    sf::Vector2f mMouseDelta{ 0.f, 0.f };

    // TODO: Reimplement Build Mode
    // std::shared_ptr<Location> mBuildGhost;

    VBox::Ptr mMenuVBox = VBox::create();
    ExpansionInterface mExpansionInterface;

public:
    using Ptr = std::unique_ptr<GameView>;

    GameView(PtrView<IApplication<StateIdsVariant>>,
             GameWindow<tgui::GuiSFML, sf::RenderWindow>,
             GameController::Ptr,
             Model::PtrConst);

    virtual ~GameView() {};

    void HandleEvent(const sf::Event&);

    void Update(const float update_delta_seconds);
};

} // namespace OpenLabora

#endif // GAMEVIEW_HPP_
