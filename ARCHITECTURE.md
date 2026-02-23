# Game Architecture Documentation 

## Overview

This document explains the complete game architecture, how the update system works, and why it's designed this way. (this mostly ai genearated document as i was lazy to write the doc my self so after ai  going through my code this was made. i have read this to ensure correctness pls do refer )
---

## Table of Contents

1. [The Big Picture](#the-big-picture)
2. [File Responsibilities](#file-responsibilities)
3. [Entity System](#entity-system)
4. [Player Class](#player-class)
5. [Animation System](#animation-system)
6. [Texture Manager](#texture-manager)
7. [Gamerender - The Organizer](#gamerender---the-organizer)
8. [tickupdate.cpp - The Orchestrator](#tickupdatecpp---the-orchestrator)
9. [game03.cpp - The Main Loop](#game03cpp---the-main-loop)
10. [Frame-by-Frame Walkthrough](#frame-by-frame-walkthrough)
11. [Adding Enemies Later](#adding-enemies-later)
12. [Summary](#summary)

---

## The Big Picture

The game has a **game loop** that runs every frame (60 times per second):

```
MAIN LOOP (repeats every frame)
├─ Handle Input (keyboard, mouse, etc)
├─ UPDATE (logic - movement, animation, etc)
├─ RENDER (draw everything on screen)
└─ Repeat
```

This is the **standard game loop pattern** used in most games.

---

## File Responsibilities

| File | Purpose | Key Responsibility |
|------|---------|-------------------|
| **game03.cpp** | MAIN LOOP | Controls the loop, calls update() and render() |
| **tickupdate.h/cpp** | UPDATE ORCHESTRATOR | Decides what to update each frame |
| **entity.h** | BLUEPRINT | Blueprint for all game objects |
| **player.h/cpp** | PLAYER ENTITY | Inherits from Entity, implements player logic |
| **gamerender.h/cpp** | RENDER MANAGER | Manages drawing and stores all entities |
| **texturemanager.h/cpp** | TEXTURE STORAGE | Loads and stores textures (images) |
| **animtimer.h/cpp** | ANIMATION | Handles sprite frame animation timing |

---

## Entity System

### What is an Entity?

An "entity" is **anything in the game that moves or needs to be drawn**:
- Player
- Enemies
- NPCs
- Items
- Anything with position, animation, texture

### Entity.h - The Contract

```cpp
class Entity {
    virtual void update(float deltaTime) = 0;  // Update logic
    virtual void draw(SDL_Renderer* renderer) = 0;  // Draw on screen
    virtual float getX() const = 0;  // Get position
    virtual float getY() const = 0;
    virtual std::string getType() const = 0;  // What type am I?
};
```

This says: **"Every entity MUST have these 5 methods."**

Think of it like a **checklist**:
- ✅ Can I update it? (movement, animation)
- ✅ Can I draw it? (render to screen)
- ✅ Can I get its position? (X, Y coords)
- ✅ What type is it? (for logic)

### Why Entity System is Powerful

**Without Entity (Bad):**
```cpp
player play;
enemy enemy1;
npc npc1;

// ❌ Update all differently
play.playerUpdate(dt);
enemy1.enemyUpdate(dt);
npc1.npcUpdate(dt);

// ❌ Draw all differently
play.playerDraw(renderer);
enemy1.enemyDraw(renderer);
npc1.npcDraw(renderer);
```

**With Entity (Good):**
```cpp
vector<Entity*> entities = {&play, &enemy1, &npc1};

// ✅ Update all the same way
for (auto e : entities) {
    e->update(dt);
    e->draw(renderer);
}
```

---

## Player Class

### player.h - What Player Has

```cpp
class player : public Entity {
private:
    float x, y;              // Position
    float speed = 200.0f;    // Movement speed
    int currentAnimState;    // Which animation (idle, run, jump)?
    animation playerAnim;    // The animation timer
};
```

### player.cpp - What Player Does

#### playerpos(deltaTime) - Handle Input & Movement

```cpp
void player::playerpos(float deltatime)
{
    // Check which keys are pressed
    if (keys[W]) {
        y -= speed * deltatime;  // Move up
        currentAnimState = 2;    // Switch to "up" animation
    }
    // ... same for S, A, D ...
    
    if (!moving) {
        currentAnimState = 1;    // Switch to idle
    }
}
```

**Why multiply by deltaTime?**
- Without it: movement would be different speed on fast vs slow computers
- With it: movement is ALWAYS the same speed (200 pixels per second)

#### updateAnimation(deltaTime) - Update Animation Frame

```cpp
void player::updateAnimation(float deltatime)
{
    // Tell animation timer to advance
    playerAnim.animtimerupdate(deltatime);
    
    // Tell animation timer which row to use
    switch(currentAnimState) {
        case 1: playerAnim.setAnimation(0, 4);  // Idle = row 0, 4 frames
        case 2: playerAnim.setAnimation(1, 4);  // Up = row 1, 4 frames
        // etc...
    }
}
```

**Why?**
- Animation timer just counts frames
- Tell it which animation to count from
- Avoids showing wrong animation while walking

#### update() - Entity Method (REQUIRED)

```cpp
void player::update(float deltaTime)
{
    playerpos(deltaTime);       // Handle input & movement
    updateAnimation(deltaTime); // Update animation frame
}
```

**This is what Gamerender calls when it says `entity->update()`**

---

## Animation System

### How Animation Works

The spritesheet layout:

```
     Frame 0    Frame 1    Frame 2    Frame 3
Row 0: [Idle]    [Idle]     [Idle]     [Idle]
Row 1: [Up]      [Up]       [Up]       [Up]
Row 2: [Down]    [Down]     [Down]     [Down]
Row 3: [Left]    [Left]     [Left]     [Left]
Row 4: [Right]   [Right]    [Right]    [Right]
```

### animtimer.cpp - What Happens Each Frame

```cpp
void animation::animtimerupdate(float deltatime)
{
    timer += deltatime;  // Accumulate time
    
    if (timer >= speed) {  // When 0.1 seconds passes
        timer -= speed;
        currentframe++;    // Go to next frame (0→1→2→3→0)
    }
}
```

**Example:**
```
Frame 0: timer = 0.05s (waiting)
Frame 1: timer = 0.08s (waiting)
Frame 2: timer = 0.12s (PASSED 0.1s threshold!)
         currentframe = 1, timer reset
Frame 3: timer = 0.02s (waiting again)
```

### getSrcRect() - What to Draw

```cpp
SDL_Rect animation::getSrcRect()
{
    return {
        currentframe * 32,    // X position in spritesheet
        currentrow * 32,      // Y position in spritesheet
        32, 32                // Width and height
    };
}
```

**Returns which pixel rectangle to copy from the spritesheet**

---

## Texture Manager

### What It Does

Stores all textures in memory so they are only loaded once:

```cpp
TextureManager texMgr;

// Load once
texMgr.Load(renderer, "player_spritesheet", "path/to/image.png");

// Use many times
SDL_Texture* tex = texMgr.gettex("player_spritesheet");
```

### Why This Matters

**❌ Bad: Load texture every frame**
```cpp
while (running) {
    SDL_Texture* tex = IMG_LoadTexture(...);  // SLOW! Every frame!
    SDL_RenderTexture(..., tex, ...);
}
```

**✅ Good: Load once, use many times**
```cpp
SDL_Texture* tex = texMgr.Load(...);  // Once at start

while (running) {
    SDL_RenderTexture(..., tex, ...);  // Fast! Just reference
}
```

---

## Gamerender - The Organizer

### gamerender.h - What It Stores

```cpp
class Gamerender {
private:
    player play;                    // The player
    TextureManager* texMgr;         // Reference to texture manager
    vector<Entity*> entities;       // List of ALL entities to update/draw
};
```

### gamerender.cpp - What It Does

#### init(texMgr) - Setup

```cpp
void Gamerender::init(TextureManager& texManager)
{
    texMgr = &texManager;           // Store reference
    entities.push_back(&play);      // Add player to entity list
}
```

**Why store a reference to TextureManager?**
- Gamerender needs to get textures when drawing
- When enemies are added, they also need the same texture manager
- One manager for the entire game

#### updateAll(deltaTime) - Update All Entities

```cpp
void Gamerender::updateAll(float deltaTime)
{
    for (auto entity : entities) {
        entity->update(deltaTime);  // Calls player::update(), enemy::update(), etc
    }
}
```

**This loops through:**
- player → calls `player::update()`
- enemy → calls `enemy::update()`
- npc → calls `npc::update()`
- etc...

#### drawAll(renderer) - Draw All Entities

```cpp
void Gamerender::drawAll(SDL_Renderer* renderer)
{
    for (auto entity : entities) {
        entity->draw(renderer);  // Calls player::draw(), enemy::draw(), etc
    }
}
```

---

## tickupdate.cpp - The Orchestrator

This is the **master conductor** that decides what happens each frame:

```cpp
void update(Gamerender& render, float deltatime)
{
    // 1. Update all entities (player, enemies, NPCs)
    updateEntities(render, deltatime);
    
    // 2. Update map logic (if needed)
    updateMap(deltatime);
    
    // 3. Update camera (if needed)
    updateCamera(deltatime);
}

void updateEntities(Gamerender& render, float deltatime)
{
    render.updateAll(deltatime);  // Tell Gamerender to update all entities
}
```

**Why separate functions?**
- Easy to add more updates later (updatePhysics, updateAI, etc)
- Clean organization
- Can enable/disable updates easily

---

## game03.cpp - The Main Loop

This is the **heartbeat** of the game:

```cpp
int main(int argc, char* argv[])
{
    // 1. SETUP
    TextureManager texMgr;
    Gamerender render;
    render.init(texMgr);
    texMgr.Load(renderer, "player_spritesheet", "path/image.png");
    
    // 2. MAIN LOOP (runs 60 times per second)
    while (running) {
        // A. INPUT
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }
        
        // B. UPDATE
        float deltatime = calculate_time_since_last_frame();
        update(render, deltatime);  // Call master update
        
        // C. RENDER
        render.preparerenderer(renderer);
        render.drawAll(renderer);
        SDL_RenderPresent(renderer);
    }
    
    // 3. CLEANUP
    texMgr.ALLTexclear();
    cleanup(state);
}
```

---

## Frame-by-Frame Walkthrough

Here's what happens when the game runs:

### Frame 1 (Player presses W)

```
1. main() - INPUT PHASE
   └─ SDL_PollEvent() detects W key

2. main() - UPDATE PHASE
   └─ update(render, deltatime=0.016s)  // 1/60th second
      └─ updateEntities(render, 0.016s)
         └─ render.updateAll(0.016s)
            └─ play.update(0.016s)
               ├─ playerpos(0.016s)
               │  ├─ detects W key
               │  ├─ y -= 200 * 0.016 = 3.2 pixels up
               │  └─ currentAnimState = 2 (up animation)
               │
               └─ updateAnimation(0.016s)
                  ├─ playerAnim.animtimerupdate(0.016s)
                  │  └─ timer += 0.016  (now 0.016s)
                  │
                  └─ setAnimation(1, 4)  // Use row 1, 4 frames

3. main() - RENDER PHASE
   └─ render.preparerenderer()  // Clear screen
   └─ render.drawAll(renderer)
      ���─ play.draw(renderer)
         ├─ getSrcRect() = {0, 32, 32, 32}  // Frame 0, row 1
         ├─ getTexture() = player_spritesheet
         └─ SDL_RenderTexture(renderer, tex, srcRect, destRect)
            └─ Draws frame 0 of row 1 (up animation frame 1)

4. SDL_RenderPresent(renderer)  // Show on screen
```

### Frame 2 (Player still holding W)

```
Timer is now: 0.016s (not enough for next frame yet)

1. playerpos() → y -= 3.2 more pixels
2. updateAnimation():
   ├─ animtimerupdate(0.016s) → timer = 0.032s (still < 0.1s)
   ├─ currentframe stays 0
3. draw() → Same frame 0 shown again
```

### Frame 7 (After ~0.1 seconds)

```
Timer is now: 0.112s (PASSED 0.1s threshold!)

1. animtimerupdate(0.016s)
   ├─ timer = 0.112s
   ���─ timer >= 0.1s? YES!
   ├─ currentframe++ → now 1
   └─ timer -= 0.1 → now 0.012s

2. getSrcRect() = {32, 32, 32, 32}  // Frame 1, row 1
3. Draws frame 1 of row 1 (up animation frame 2)
```

This repeats until currentframe reaches 4, then resets to 0.

---

## Adding Enemies Later

Once this works, adding an enemy is simple:

```cpp
// Create enemy class
class Enemy : public Entity {
    float x, y;
    animation anim;
    
    void update(float deltaTime) override { /* enemy logic */ }
    void draw(SDL_Renderer* r) override { /* enemy drawing */ }
    float getX() const override { return x; }
    float getY() const override { return y; }
    std::string getType() const override { return "enemy"; }
};

// In gamerender.cpp init():
void Gamerender::init(TextureManager& texManager)
{
    texMgr = &texManager;
    entities.push_back(&play);      // Player
    entities.push_back(&enemy);     // NEW: Enemy
}

// Everything else works automatically!
// update() calls render.updateAll()
// render.updateAll() loops through ALL entities
// Enemy updates without changing any other code!
```

---

## Summary

### Architecture Benefits

| Problem | Solution | Why |
|---------|----------|-----|
| Updating different entities differently | Entity base class + virtual methods | One interface, many implementations |
| Adding new entities breaks old code | Entity list in Gamerender | New entities auto-included |
| Game loop scattered everywhere | Centralized tickupdate.cpp | One place to control game flow |
| Texture loading every frame | TextureManager with caching | Fast rendering |
| Animation timing different on slow computers | deltaTime everywhere | Framerate-independent |
| Confusing where things happen | Clear file responsibilities | Easy to debug |

### Code Flow Summary

```
game03.cpp (Main Loop)
  ├─ INPUT: Handle keyboard/mouse
  ├─ UPDATE: Call update()
  │  └─ tickupdate.cpp
  │     └─ updateEntities()
  │        └─ gamerender.updateAll()
  │           └─ entity->update()  (for each entity)
  │              └─ player::update()
  │                 ├─ playerpos()
  │                 └─ updateAnimation()
  │
  └─ RENDER: Call drawAll()
     └─ gamerender.drawAll()
        └─ entity->draw()  (for each entity)
           └─ SDL_RenderTexture()
```

---

