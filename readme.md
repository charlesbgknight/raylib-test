# Gaiarreria

Shameless Terrraria ripoff to sandbox while i learn  & experiment with C++

## Ideas/ Future Plans
- refactor all classes to C++20-style modules 
- lighting system:
  - lightsource-subtracted mask, or
  - per-tile light level
  - much later 2D raytraced vector lighting? strategic potential

## Immediate plan
Foundations of structure & engine, gradually introduce player mechanics and NPC POCs

### Worldgen
- Implement tilemap draw system 
- Freecam view control 
- Later, broad structure & noise patterns 
#### Structure 
World components will be extracted into disparate generation processes to allow
composed design & parameter adjustment.  
- Perlin noise for natural patterns?

### NPCs
- tile collosion system first (quadtree collision? per-vertex velocity iteration?)
- basic test AIs before player interaction

