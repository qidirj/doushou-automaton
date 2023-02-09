/*
game.h
Main game assets.
*/

#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <string>
#include <vector>

#include "data.h"

namespace Game
{
  class game
  {
  private:
    int playerCount;
    std::vector<int> playerLevels;
    std::vector<std::string> playerNames;
    void giveLevels()
    {
      for (int i = 1; i <= 4; ++i)
        for (int j = 0; j < levelCounts[playerCount][i]; ++j)
          playerLevels.push_back(i);
      std::shuffle(playerLevels.begin(), playerLevels.end(), rng);
    }

  public:
    game() { clearGame(); }
    game(int count)
    {
      clearGame();
      initGame(count);
    }
    ~game() { clearGame(); }

    void clearGame()
    {
      // TODO: remember to clear it when you added new thing.
      playerCount = 0;
      playerLevels.clear();
      playerNames.clear();
    }
    void initGame(int count)
    {
      playerCount = count;
      for (int i = 0; i < count; ++i)
        playerNames.push_back(std::to_string(i));
      giveLevels();
    }
  };
}

#endif
