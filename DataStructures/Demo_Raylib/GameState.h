#pragma once

class GameState
{
public:
	void Start() { OnStart(); }
	void Update() { OnUpdate(); }
	void Draw() { OnDraw(); }
	void Exit() { OnExit(); }

	virtual int GetNextState() { return -1; }

protected:
	virtual void OnStart() { }
	virtual void OnUpdate() { }
	virtual void OnDraw() { }
	virtual void OnExit() { }
};
