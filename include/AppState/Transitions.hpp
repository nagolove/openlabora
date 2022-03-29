#ifndef TRANSITIONS_HPP_
#define TRANSITIONS_HPP_

#include <memory>
#include <concepts>
#include <TGUI/Core.hpp>
#include <TGUI/Backends/SFML.hpp>

#include "StateIds.hpp"
#include "AppStateDefs.hpp"
#include "IApplication.hpp"
#include "Misc/PtrView.hpp"
#include "Resource/IResourceManager.hpp"
#include "GameWindow.hpp"

namespace OpenLabora
{

/**
 * Callable that allows transitions between application states. Intended to be
 * used as callable for std::visit
 *
 * @tparam TGui - A GUI library class
 * @tparam TWindow - Render window class
 *
 * @arg Empty struct which represents one of possible application states
 * @return New AppState object or std::nullopt if there is no overload for @arg
 */
template <class TGui, class TWindow>
class Transitions final
{
    using IApplication = IApplication<StateIdsVariant>;

    template <class TAppState>
    TAppState CreateState()
    {
        using ModelT = typename TAppState::ModelType;
        using ControllerT = typename TAppState::ControllerType;
        using ViewT = typename TAppState::ViewType;
        using MVCState = AppState<ModelT, ViewT, ControllerT>;

        auto model = std::make_shared<ModelT>();
        auto ctlr = std::make_shared<ControllerT>(mApp, mResManager, model);
        auto view = std::make_unique<ViewT>(mApp, mWindow, ctlr, model);
        return MVCState{ model, std::move(view), ctlr };
    }

    PtrView<IApplication> mApp;
    IResourceManager::Ptr mResManager;
    GameWindow<TGui, TWindow> mWindow;

public:
    using StateOpt = std::optional<State>;

    Transitions(PtrView<IApplication> app,
                IResourceManager::Ptr res_manager,
                GameWindow<TGui, TWindow> window)
        : mApp{ app }, mResManager{ res_manager }, mWindow{ window }
        {}

// ----------------------- ADD ALL TRANSITIONS HERE -----------------------------
    StateOpt operator()(const MainMenuStateId&)
    {
        return CreateState<MainMenuState>();
    };

    StateOpt operator()(const DuelStateId&)
    {
        return CreateState<DuelState>();
    };

    StateOpt operator()(const FinalStateId&)
    {
        return CreateState<FinalState>();
    };

    template<class T>
    StateOpt operator()(const T&)
    {
        return std::nullopt;
    }
};

} // namespace OpenLabora

#endif // TRANSITIONS_HPP_
