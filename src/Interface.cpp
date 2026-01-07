#include "Interface.hpp"
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

//Constructeur
Interface::Interface(Application& app)
    : application(app) {}

bool Interface::init() {
    if (!SDL_Init(SDL_INIT_VIDEO))
        return false;

    window = SDL_CreateWindow(
        "Genetic Algorithm Visualizer",
        1280, 720,
        SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(window, nullptr);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    return true;
}

/*
 * Une frame graphique :
 *  - gestion événements
 *  - affichage ImGui
 */
void Interface::frame() {
    step = play = reset = false;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);
        if (event.type == SDL_EVENT_QUIT)
            quitter = true;
    }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    // Fenêtre de contrôle principale
  
    ImGui::Begin("Contrôles");

    if (ImGui::Button("Step")) step = true;
    ImGui::SameLine();
    if (ImGui::Button("Play")) play = true;
    ImGui::SameLine();
    if (ImGui::Button("Reset")) reset = true;

    ImGui::Separator();
    ImGui::Text("Paramètres génétiques");

    ImGui::SliderFloat("Taux mutation", &tauxMutation, 0.0f, 1.0f);
    ImGui::SliderFloat("Taux croisement", &tauxCroisement, 0.0f, 1.0f);
    ImGui::SliderInt("Taille tournoi", &tailleTournoi, 2, 10);
    ImGui::SliderInt("Nombre parents", &nombreParents, 2, 100);

    ImGui::End();

    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 20, 20, 30, 255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}

/*
 * Affiche le meilleur individu courant
 * (solution approchée du problème)
 */
void Interface::afficherMeilleur(const Individu& meilleur) {
    ImGui::Begin("Meilleure solution");

    ImGui::Text("Fitness : %.2f", meilleur.getFitness());

    const auto& chromosome = meilleur.getChromosome();
    ImGui::Text("Chromosome :");

    // Affichage gène par gène
    for (size_t i = 0; i < chromosome.size(); ++i) {
        ImGui::SameLine();
        if (chromosome[i] == 1)
            ImGui::TextColored(ImVec4(0,1,0,1), "[1]");
        else
            ImGui::TextColored(ImVec4(1,0,0,1), "[0]");
    }

    ImGui::End();
}

void Interface::shutdown() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// === Getters (demandes utilisateur) ===
bool Interface::demandeQuitter() const { return quitter; }
bool Interface::demandeStep() const { return step; }
bool Interface::demandePlay() const { return play; }
bool Interface::demandeReset() const { return reset; }

// === Paramètres ===
double Interface::getTauxMutation() const { return tauxMutation; }
double Interface::getTauxCroisement() const { return tauxCroisement; }
int Interface::getTailleTournoi() const { return tailleTournoi; }
int Interface::getNombreParents() const { return nombreParents; }
