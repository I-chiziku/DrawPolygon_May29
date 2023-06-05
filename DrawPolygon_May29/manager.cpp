#include	"polygon2D.h"
#include	"renderer.h"
#include	"manager.h"
#include	"field.h"
#include	"camera.h"
#include "GameObject.h"
#include <list>

// グローバル変数
//Field*		g_Field{};
//Polygon2D*	g_Polygon{};
//Camera*		g_Camera{};
std::list<GameObject*> gameObject;

void Manager::Init(Application* ap)
{
	// タイマ解像度を１ミリ秒にする
	timeBeginPeriod(1);

	// レンダラーを初期化
	Renderer::Init(ap);


	gameObject.push_back(new Polygon2D());
	gameObject.push_back(new Camera());
	gameObject.push_back(new Field());

	for (auto itr : gameObject) {
		itr->Init();
	}


	//// ポリゴン初期化
	//g_Polygon = new Polygon2D();
	//g_Polygon->Init();


	//// カメラ初期化
	//g_Camera = new Camera();
	//g_Camera->Init();

	//// フィールド初期化
	//g_Field = new Field();
	//g_Field->Init();

}

void Manager::Uninit()
{
	// レンダラー終了処理
	Renderer::Uninit();

	for (auto itr : gameObject) {
		itr->Uninit();
	}

	//// ポリゴン削除
	//g_Polygon->Uninit();
	//delete	g_Polygon;


	//// カメラ終了処理
	//g_Camera->Uninit();
	//delete	g_Camera;

	//// フィールド終了処理
	//g_Field->Uninit();
	//delete	g_Field;

	// タイマ解像度を元に戻す
	timeEndPeriod(1);
}

void Manager::Update(uint64_t d)
{
	/*g_Camera->Update();
	g_Field->Update();
	g_Polygon->Update();
	g_Polygon->Update();*/

	for (auto itr : gameObject) {
		itr->Update();
	}

}

void Manager::Draw(uint64_t d)
{
	Renderer::Begin();
	/*g_Camera->Draw();
	g_Field->Draw();
	g_Polygon->Draw();*/
	for (auto itr : gameObject) {
		itr->Draw();
	}
	Renderer::End();
}
