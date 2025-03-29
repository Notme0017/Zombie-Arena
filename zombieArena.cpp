#include "zombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena)
{
    const int TILE_SIZE = 50;
    const int TILE_TYPE = 3;
    const int VERTS_IN_QUADS = 4;

    int worldWidth = arena.width / TILE_SIZE;
    int worldHeight = arena.height / TILE_SIZE;

    //setting the primitive type
    rVA.setPrimitiveType(Quads);
    //setting the size of the world
    rVA.resize(worldWidth * worldHeight * VERTS_IN_QUADS);
    //starting at the beginning of the vertex array 
    int currentVertex = 0;

    for (int w = 0; w < worldWidth; w++)
    {
        for (int h = 0; h < worldHeight; h++)
        {
            //Positioning each vertex in current quad
            rVA[currentVertex + 0].position =
                Vector2f(w * TILE_SIZE, h * TILE_SIZE);
            
            rVA[currentVertex + 1].position =
                Vector2f(w * TILE_SIZE + TILE_SIZE, h * TILE_SIZE);

            rVA[currentVertex + 2].position =
                Vector2f(w * TILE_SIZE + TILE_SIZE, h * TILE_SIZE + TILE_SIZE);

            rVA[currentVertex + 3].position =
                Vector2f(w * TILE_SIZE, h * TILE_SIZE + TILE_SIZE);


            //Defining the texture
            //for the walls
            if (h == 0 || h == worldHeight - 1 ||
                w == 0 || w == worldWidth - 1)
            {
                rVA[currentVertex + 0].texCoords =
                    Vector2f(0, 0 + TILE_TYPE * TILE_SIZE);

                rVA[currentVertex + 1].texCoords =
                    Vector2f(TILE_SIZE, 0 + TILE_TYPE * TILE_SIZE);

                rVA[currentVertex + 2].texCoords =
                    Vector2f(TILE_SIZE, 0 + TILE_TYPE * TILE_SIZE + TILE_SIZE);

                rVA[currentVertex + 3].texCoords =
                    Vector2f(0, 0 + TILE_TYPE * TILE_SIZE + TILE_SIZE);

            }
            else
            {
                //giving any random texture to the arena
                srand(int(time(0)) + h * w - h);
                int MorG = rand() % TILE_TYPE;
                int VerticalOffset = MorG * TILE_SIZE;

                rVA[currentVertex + 0].texCoords =
                    Vector2f(0, VerticalOffset);

                rVA[currentVertex + 1].texCoords =
                    Vector2f(TILE_SIZE, VerticalOffset);

                rVA[currentVertex + 2].texCoords =
                    Vector2f(TILE_SIZE, TILE_SIZE + VerticalOffset);

                rVA[currentVertex + 3].texCoords =
                    Vector2f(0, TILE_SIZE + VerticalOffset);
            }

            //Positioning the vertex to next 4
            currentVertex += VERTS_IN_QUADS;
        }
    }

    return TILE_SIZE;
}
