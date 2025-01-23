#include "GameScene.h"

GameScene::GameScene()
{
    // Playerのインスタンスを動的に確保
    player_ = new Player();
    fixedNum_ = new FixedNum();
    card_ = new Card();
    skill_ = new Skill();
    texture_ = new Texture;
    boss = new Boss();
    backT_;
}

GameScene::~GameScene()
{
    // 確保したメモリを解放
    delete player_;
    delete fixedNum_;
    delete card_;
    delete skill_;
    delete texture_;
    delete boss;
}

void GameScene::Initialize(int backT)
{   
    backT_ = backT;
    //カードの初期化
    Vector2 cardPos[fixedNum_->cardNum]{};
    Vector2 cardSize;
    bool haveCardF[fixedNum_->cardNum]{};

    for (int i = 0; i < fixedNum_->cardNum; i++)
    {
        cardPos[i] = Vector2(350.f + i * 100.f, 600.f);
        cardSize = { 50.f,100.f };
        haveCardF[i] = true;
    }
    card_->Initialize(cardPos,cardSize,haveCardF);

   

    //スキルの初期化
    Vector2 listBottomSize = {50.f,50.f};
    bool isListBottom = false;
    Vector2 skillBottomPos[FixedNum::skillNum]{};
    Vector2 skillBottomSize[FixedNum::skillNum]{};
    bool isSkillBottomFlag[FixedNum::skillNum]{};

    for (int i = 0; i < fixedNum_->skillNum; i++)
    {
        skillBottomPos[i] = { i * 300.f+300.f,100.f };
        skillBottomSize[i] = { 50.f,50.f };
        isSkillBottomFlag[i] = false;
    }
    Vector2 listBottomPos = skillBottomPos[0];
    Vector2 listBottomSpeed = {300.f,300.f};
    skill_->Initialize(listBottomPos, listBottomSize, isListBottom, skillBottomPos, skillBottomSize, isSkillBottomFlag);
    

    // Playerの初期化用データ
    Vector2 playerPos = { 1050.f, 500.f };
    Vector2 playerSize = { 50.f, 100.f };
    Vector2 playerMovePos = cardPos[0];
    Vector2 hpPosition = { 400.f,550.f };
    int playerHp = 10;
    bool plyaerIsAlive = true;
    bool playerIsTurn = false;
    Vector2 playerCardMoveSpeed = { cardSize.x * 2,cardSize.y * 2, };
    bool cardIsCollision = false;
    
    //Vector2 
    // player_の初期化
    player_->Initialize(playerPos, playerSize, playerHp, hpPosition, plyaerIsAlive, playerIsTurn, playerMovePos, playerCardMoveSpeed, cardIsCollision, listBottomPos, listBottomSpeed);

    Vector2 bossPos = { 100.f,50.f };
    Vector2 bossSize = { 200.f,200.f };
    bool isBossTrue = false;
    int attck = 0;
    int hp = 10;
    Vector2 hpPos = { 400.f,200.f };
    int bossRandomAttck[FixedNum::haveCard] = { 1,3,5 };
    bool bossIsAlive = true;
    boss->Initialize(bossPos, bossSize, isBossTrue, attck, hp, hpPos, bossRandomAttck, bossIsAlive);
}

    
void GameScene::Update()
{
    skill_->Update(*player_);
    // Playerの更新処理
    player_->BattleUpdate();

    ChecAllCollisiions();

    if (player_->attck_ != 0)
    {
        boss->AttckRandom();
        player_->attck_ = 0;
    }

}

void GameScene::Draw()
{
    Novice::DrawSprite(0, 0, backT_, 1, 1, 0.0f, WHITE);
    skill_->Draw(texture_);
    // Playerの描画処理
    player_->BattleDraw(texture_);

    card_->BattleDraw(texture_);

    boss->Draw(texture_->oneBoss);
}

bool GameScene::IsCollision(AABB aabb1, AABB aabb2)
{
    bool ATFlag = false;

    if (aabb1.max.y > aabb2.min.y && aabb1.min.y < aabb2.max.y) {

        if (aabb1.max.x > aabb2.min.x && aabb1.min.x < aabb2.max.x) {
            ATFlag = true;
        }
    }
    else {
        ATFlag = false;
    }
    

    return ATFlag;
}

void GameScene::ChecAllCollisiions()
{
    AABB playerCardAABB = player_->GetCardAABB();

    if (!card_ || !fixedNum_) return;
    if (player_->isSkillActive_ == false)
    {
        for (int i = 0; i < fixedNum_->cardNum; i++)
        {
            if (i < 0 || i >= fixedNum_->cardNum) continue;

            if (card_->haveCardF_[i])
            {
                AABB cardAABB = card_->GetCardAABB(i);

                if (IsCollision(playerCardAABB, cardAABB))
                {
                    // 衝突した場合の処理
                    player_->cardIsCollision_ = true;

                    //スペースキーを押したら
                    if (player_->cardConfirmed())
                    {
                        //カードが持っている攻撃力をplayerが使えるようになる
                        player_->attck_ = card_->num[i];
                        card_->num[i] = 0;
                        card_->haveCardF_[i] = false;
                        //player_->cardAttck(*card_);
                    }
                }
            }
        }
    }
   
    if (player_->isSkillActive_)
    {
        ///スキルの当たり判定
        AABB playerSkillAABB = player_->GetSkillAABB();
        if (!skill_ || !fixedNum_) return;
        for (int i = 0; i < fixedNum_->skillNum; i++)
        {
            if (i < 0 || i >= fixedNum_->skillNum) continue;

            AABB skillAABB = skill_->GetSkillAABB(i);

            if (IsCollision(playerSkillAABB, skillAABB))
            {
                // 衝突した場合の処理
                player_->skillIsCollision_ = true;

                // スペースキーを押したら
                if (player_->skillConfirmed())
                {
                    // スキルボタンフラグがまだ立っていない場合にだけ処理を行う
                    if (!skill_->isSkillBottomFlag_[i])
                    {
                        skill_->isSkillBottomFlag_[i] = true;  // 初めてスキルが発動されたときにフラグを立てる
                        if (skill_->isSkillBottomFlag_[0])
                        {
                            skill_->BattleTwice(*card_);
                        }
                        else if (skill_->isSkillBottomFlag_[1])
                        {
                            skill_->BattleRandomNum(*card_);
                        }
                    }
                    player_->isSkillActive_ = false;
                }

            }
        }
    }
    
}


