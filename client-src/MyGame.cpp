#include "MyGame.h"

void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    /*if (cmd == "INIT_DATA") {
        std::cout << "ARGS SIZE" << args.size() << std::endl;
        if (args.size() == 6) {
            std::cout << "set init data" << std::endl;
            game_data.player1X = stoi(args.at(0));
            game_data.player2X = stoi(args.at(1));
            game_data.player1Y = stoi(args.at(2));
            game_data.player2Y = stoi(args.at(3));
            game_data.ballX = stoi(args.at(4));
            game_data.ballY = stoi(args.at(5));
        }
    } else */if (cmd == "GAME_DATA") {
        //std::cout << "ARGS SIZE" << args.size() << std::endl;
        // 
        // we should have exactly 6 arguments
        if (args.size() == 6) {
            game_data.player1X = stoi(args.at(0));
            game_data.player2X = stoi(args.at(1));
            game_data.player1Y = stoi(args.at(2));
            game_data.player2Y = stoi(args.at(3));
            game_data.ballX = stoi(args.at(4));
            game_data.ballY = stoi(args.at(5));
        }
    } else {
        std::cout << "CMD RECEIVED: " << cmd << std::endl;
    }

    
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
    }
}

void MyGame::update() {
    player1.x = game_data.player1X;
    player1.y = game_data.player1Y;
    player2.x = game_data.player2X;
    player2.y = game_data.player2Y;
    ball.x = game_data.ballX;
    ball.y = game_data.ballY;
}

void MyGame::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player1);
    SDL_RenderDrawRect(renderer, &player2);
    SDL_RenderDrawRect(renderer, &ball);
}