#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	b(gfx),
	rnd(std::random_device()()),
	snake({ 3,3 }),
	g(rnd, b, snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (gameStart) {
		//przypisanie przyciskom na strzałkach odpowiedniej wartosci koordynatow o ktora snake ma sie poruszyc
		if (!gameOver) {
			if (wnd.kbd.KeyIsPressed(VK_UP)) {
				loc_move = { 0,-1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
				loc_move = { 1,0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
				loc_move = { 0,1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
				loc_move = { -1, 0 };
			}
		}

		//jezeli snake porusza sie przy kazdej klatce a nasza gra jest w 60 fps oznacza to ze snake porusza sie domyslnie 60 kratek na sekundke
		//aby temu zapobiec wprowadzilem zmienne ktore wykonuja czynnosc poruszania sie jedynie kiedy licznik moveCounter bedzie mial wartosc snakeSpeed (20)
		moveCounter++;
		if (moveCounter >= snakeSpeed) {
			moveCounter = 0;
			//sprawdzenie warunku konca gry poprzez sprawdzenie czy nastepny ruch jest w granicach okna, jesli isInside jest prawdziwy snake moze wykonac ruch
			const Location next = snake.getNextLocation(loc_move);
			if (!b.isInside(next) || snake.isColidedWithoutLastPart(next)) {
				gameOver = true;
			}
			else {
				bool eat = next == g.getLocation();
				if (eat) {
					snake.Grow();
				}

				snake.Move(loc_move);
				if (eat) {
					g.Spawn(rnd, b, snake);
				}
			}
		}
	}
	else {
		gameStart = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (gameStart) {
		snake.Draw(b);
		g.Draw(b);
		if (gameOver) {
			SpriteCodex::DrawGameOver(335, 225, gfx);
		}
		b.drawBorder();
	}
	else {
		SpriteCodex::DrawTitle(335, 225, gfx);
	}
}