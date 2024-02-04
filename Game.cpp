#include "Game.h"

void Game::Initialize() {
	player_ = new Player();
	enemy_ = new EnemyManager();
	shake_ = new Shake();
	isStop_ = enemy_->GetStop();

	random_ = { 0,0 };

	GameOverGH_ = Novice::LoadTexture("./resources./GameOver.png");
	ClearGH_ = Novice::LoadTexture("./resources./Clear.png");
	LeftClickGH_ = Novice::LoadTexture("./resources./LeftClick.png");

	cnt_ = 0;
}

void Game::Update() {
	cnt_++;

	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	shake_->Update(isStop_);

	isStop_ = enemy_->GetStop();

	if (isGameOver_ == false || isClear_ == false) {
		if (*isStop_ == false) {
			player_->Update();
			enemy_->Update(player_->GetBullet(), player_->GetPos(), player_->GetSpeed());
		}
		else {
			random_ = shake_->GetRandom();
			stopCnt_++;
			if (stopCnt_ == 10) {
				*isStop_ = false;
				stopCnt_ = 0;
			}
		}
	}

	player_->SetIsHit(enemy_->GetIsHitPlayer());

	if (cnt_ == 100) {
		SetIsPopEnemy(1);
	}
	if (cnt_ == 500) {
		SetIsPopEnemy(1);
	}
	if (cnt_ == 900) {
		SetIsPopEnemy(2);
	}
	if (cnt_ == 1100) {
		SetIsPopEnemy(3);
	}
	if (cnt_ == 1500) {
		SetIsPopEnemy(2);
	}
	if (cnt_ == 2000) {
		SetIsPopEnemy(2);
	}
	if (cnt_ == 2700) {
		SetIsPopEnemy(3);
	}
	if (cnt_ == 3200) {
		SetIsPopEnemy(1);
	}
	if (cnt_ == 3700) {
		SetIsPopEnemy(2);
	}
	if (cnt_ == 4300) {
		SetIsPopEnemy(2);
	}
	if (cnt_ == 4500) {
		SetIsPopEnemy(3);
	}
	if (cnt_ == 5000) {
		SetIsPopEnemy(1);
	}
	if (cnt_ == 6000) {
		isClear_ = true;
	}

	PopEnemySet1(1);
	PopEnemySet2(1);
	PopEnemySet3(1);

	if (player_->GetHP() <= 0) {
		isGameOver_ = true;
	}
	if (isGameOver_ == true) {
		gameOverCount_++;
		if (gameOverCount_ == 100) {
			SceneManager::SetNextScene(new Title);
		}
	}
	if (isClear_ == true) {
		ClearCount_++;
		if (ClearCount_ == 100) {
			SceneManager::SetNextScene(new Title);
		}
	}
}

void Game::Draw() {
	Novice::GetMousePosition(&mouX_, &mouY_);

	Novice::DrawBox(-100 + int(random_.vector2[0]), -100 + int(random_.vector2[1]), 1480, 920, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(100 + int(random_.vector2[0]), 100 + int(random_.vector2[1]), 1080, 520, 0.0f, 0xFFFFFFFF, kFillModeWireFrame);
	enemy_->Draw(random_);
	player_->Draw();
	Novice::DrawLine(mouX_, mouY_, 640, 320, 0xFFFFFFFF);
	Novice::DrawSprite(1000 + int(random_.vector2[0]), 20 + int(random_.vector2[1]), LeftClickGH_, 1, 1, 0.0f, 0xFFFFFFFF);

	if (isGameOver_ == true) {
		Novice::DrawSprite(640 - 300, 360 - 32, GameOverGH_, 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (isClear_ == true) {
		Novice::DrawSprite(640 - 300, 360 - 32, ClearGH_, 1, 1, 0.0f, 0xFFFFFFFF);
	}
}

void Game::PopEnemySet1(int setCnt) {
	static int cnt = 0;

	if (isPopEnemySet1_ == true) {
		if (cnt > 0) {
			cnt++;
		}
		else {
			cnt = setCnt;
		}

		if (cnt == 1) {
			enemy_->PopEnemy({ 1200,200 }, { -1,0 }, 5);
			enemy_->PopEnemy({ 1210,250 }, { -1,0 }, 5);
			enemy_->PopEnemy({ 1220,300 }, { -1,0 }, 5);
			enemy_->PopEnemy({ 1230,350 }, { -1,0 }, 5);
		}
		if (cnt == 80) {
			enemy_->PopEnemy({ 10,400 }, { 1,0 }, 5);
			enemy_->PopEnemy({ 20,450 }, { 1,0 }, 5);
			enemy_->PopEnemy({ 30,500 }, { 1,0 }, 5);
			enemy_->PopEnemy({ 40,550 }, { 1,0 }, 5);
		}
		if (cnt == 100) {
			enemy_->PopEnemy({ 10,320 }, { 1,0 }, 10);
			enemy_->PopEnemy({ 10,360 }, { 1,0 }, 10);
		}
		if (cnt == 270) {
			enemy_->PopEnemy({ 300,10 }, { 1,1 }, 6);
			enemy_->PopEnemy({ 350,20 }, { 1,1 }, 6);
			enemy_->PopEnemy({ 600,10 }, { 1,1 }, 6);
			enemy_->PopEnemy({ 650,20 }, { 1,1 }, 6);
			cnt = 0;
			isPopEnemySet1_ = false;
		}
	}
}

void Game::PopEnemySet2(int setCnt) {
	static int cnt = 0;

	if (isPopEnemySet2_ == true) {
		if (cnt > 0) {
			cnt++;
		}
		else {
			cnt = setCnt;
		}

		if (cnt == 1) {
			enemy_->PopEnemy({ 500,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 550,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 800,700 }, { 0,-1 }, 2);
			enemy_->PopEnemy({ 850,700 }, { 0,-1 }, 2);
		}
		if (cnt == 200) {
			enemy_->PopEnemy({ 500,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 550,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 400,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 450,20 }, { 0,1 }, 2);
			enemy_->PopEnemy({ 800,700 }, { 0,-1 }, 2);
			enemy_->PopEnemy({ 850,700 }, { 0,-1 }, 2);
			enemy_->PopEnemy({ 700,700 }, { 0,-1 }, 2);
			enemy_->PopEnemy({ 750,700 }, { 0,-1 }, 2);
			cnt = 0;
			isPopEnemySet2_ = false;
		}
	}
}

void Game::PopEnemySet3(int setCnt) {
	static int cnt = 0;

	if (isPopEnemySet3_ == true) {
		if (cnt > 0) {
			cnt++;
		}
		else {
			cnt = setCnt;
		}

		if (cnt == 1) {
			enemy_->PopEnemy({ -99,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -70,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -40,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -10,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ 1370,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1330,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1290,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1250,360 }, { -1,0 }, 2);
		}
		if (cnt == 200) {
			enemy_->PopEnemy({ -99,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -70,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -40,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ -10,360 }, { 1,0 }, 2);
			enemy_->PopEnemy({ 1370,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1330,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1290,360 }, { -1,0 }, 2);
			enemy_->PopEnemy({ 1250,360 }, { -1,0 }, 2);
			cnt = 0;
			isPopEnemySet3_ = false;
		}
	}
}

void Game::SetIsPopEnemy(int Set) {
	if (Set == 1) {
		isPopEnemySet1_ = true;
	}
	if (Set == 2) {
		isPopEnemySet2_ = true;
	}
	if (Set == 3) {
		isPopEnemySet3_ = true;
	}
}

