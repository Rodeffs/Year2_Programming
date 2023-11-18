#pragma once

class iNotifyPropertyChanging {
private:
	bool active;
	bool allow;

protected:
	void (*functionNPChanging)();

public:
	explicit iNotifyPropertyChanging(bool act = false, bool all = true, void (*func)() = nullptr) : active{act}, allow{all}, functionNPChanging{func} {}

	void AddNPChangingListener() {
		active = true;
	}

	void RemoveNPChangingListener() {
		active = false;
	}

	bool NPChangingisActive() {
		return active;
	}

	virtual void allowChanges(bool answer) = 0;

	virtual ~iNotifyPropertyChanging() = default;

	virtual void OnPropertyChanging(void (*f)()) = 0;
};
