# RPG

RPG Game
Project started: 9/9/2022

              What the game will have and look like
Will have-
  (COMPLETED)

  (WORK IN PROGRESS)
  • Easy Settings (JSON)

  (NOT STARTED)
  • World Editor
  • Start Screen
  • Game over Screen
  • Settings menu
  • Dialogue
  • NPC/Environment Interactions
  • GUI Scaling? (If i figure it out)

Will look like (Gameplay)-
  (COMPLETED)

  (WORK IN PROGRESS)

  (NOT STARTED)
  • Health bar at top left of screen
  • Player face sprite to the left of health bar
  • Inventory (Either a keybind to open inventory or a on screen button for it, or both)
  • Character screen (Armor, keybind/screen button or both)
  • Hotbar (Placed in bottom center of screen, 3 slots)
  • Leveling (VIT, STR, AGI, DEF, INT)


  • If possible and if I can figure it out,
    Add post processing/Lighting

Classes that will be needed
  (COMPLETED)
  
  (WORK IN PROGRESS)
  • Hitbox
  • Entity - uses Hitbox
      • Will include damage calculation
  • Player - uses Entity
  • Enemy - uses Entity (Enemies will randomly move but will attack players when near)
  • Perspective (Will handle views)
  • Map (Will gather all level information, display game objects,
         check collision with entities and walls, and handle all entities)

  (NOT STARTED)
  • Passive - uses Entity (Passives will randomly move)
  • Inventory (Includes hotbar and character screen)
  • Item (Includes weapon and items *CONSUMABLES*)
  • MainMenu
  • GameOver
  • SettingsMenu
  • Editor

  If lighting/post processing is added
  • LightSource
