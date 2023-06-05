#include	"polygon2D.h"
#include	"renderer.h"
#include	"manager.h"
#include	"field.h"
#include	"camera.h"
#include "GameObject.h"
#include <list>

// �O���[�o���ϐ�
//Field*		g_Field{};
//Polygon2D*	g_Polygon{};
//Camera*		g_Camera{};
std::list<GameObject*> gameObject;

void Manager::Init(Application* ap)
{
	// �^�C�}�𑜓x���P�~���b�ɂ���
	timeBeginPeriod(1);

	// �����_���[��������
	Renderer::Init(ap);


	gameObject.push_back(new Polygon2D());
	gameObject.push_back(new Camera());
	gameObject.push_back(new Field());

	for (auto itr : gameObject) {
		itr->Init();
	}


	//// �|���S��������
	//g_Polygon = new Polygon2D();
	//g_Polygon->Init();


	//// �J����������
	//g_Camera = new Camera();
	//g_Camera->Init();

	//// �t�B�[���h������
	//g_Field = new Field();
	//g_Field->Init();

}

void Manager::Uninit()
{
	// �����_���[�I������
	Renderer::Uninit();

	for (auto itr : gameObject) {
		itr->Uninit();
	}

	//// �|���S���폜
	//g_Polygon->Uninit();
	//delete	g_Polygon;


	//// �J�����I������
	//g_Camera->Uninit();
	//delete	g_Camera;

	//// �t�B�[���h�I������
	//g_Field->Uninit();
	//delete	g_Field;

	// �^�C�}�𑜓x�����ɖ߂�
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
