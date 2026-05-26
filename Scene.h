#pragma once
class Scene {
public:
	virtual ~Scene();
	virtual void Initialize() = 0;	// 初期化処理
	virtual void Update() = 0;		// 更新処理
	virtual void DrawBGSprite() = 0;// 描画処理
	virtual void DrawFGSprite() = 0;// 描画処理
	virtual void DrawModel() = 0;   // 描画処理
	virtual void ImGuiDraw() = 0;   // ImGuiの描画処理
	// virtualと"= 0"を組み合わせることで純粋仮想関数を定義(子クラスで必ず実装する事)
};
