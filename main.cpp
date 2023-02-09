#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

const long long game_ver = 2, game_date = 20230208;

#pragma region LANGUAGE

std::map<std::string, std::string> lang;
int readLanguagePack(std::string locale)
{
  std::ifstream fin;

  fin.open("language-pack-" + locale + ".ini");
  if (fin.bad())
    return -1;

  std::string a, b;
  while (fin >> a >> b)
  {
    if (lang.count(a))
    {
      lang[a] = b;
      std::clog << "[WARNING] Duplicate key in language pack " << locale << "." << std::endl;
    }
    else
      lang[a] = b;
  }
  return lang.size();
}

#pragma endregion LANGUAGE

std::string gameTitle;
std::mt19937_64 rng;
int main()
{
  freopen("main.log", "w", stderr);
  rng.seed(std::random_device{}());
  int cnt = readLanguagePack("zh-cn");
  if (cnt >= 0)
    std::clog << "[INFO] Successfully read " << cnt << ((cnt <= 1) ? " entry" : " entries") << " from language pack "
              << "zh-cn"
              << "." << std::endl;
  else
  {
    std::clog << "[ERROR] Error occurred when reading language pack "
              << "zh-cn"
              << "." << std::endl;
    return 1;
  }
  if (!lang.count("--lang-ver"))
  {
    std::clog << "[ERROR] Error occurred when parsing language pack "
              << "zh-cn"
              << ": pack broken." << std::endl;
    return 1;
  }
  std::stringstream __ver;
  long long ___ver;
  __ver << lang["--lang-ver"];
  __ver >> ___ver;
  if (___ver < game_date)
  {
    std::clog << "[ERROR] Error occurred when parsing language pack "
              << "zh-cn"
              << ": pack too old." << std::endl;
    return 1;
  }
  printf("\033[2J\033[1;1H");
  printf("\033[1m%s\033[0m\n", lang["title"].c_str());
  printf("\033[91;1m[1]\033[0m \033[31m%s\033[0m\n", lang["begin-game"].c_str());
  char ch = '\0';
  while (ch < '1' || ch > '1')
  {
    while (!kbhit())
      ;
    ch = getch();
  }
  if (ch == '1')
    game::beginNew();
  return 0;
}
