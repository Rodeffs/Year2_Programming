#pragma once

class iNotifyPropertyChanging {
private:
	bool active;

protected:
	void (*functionNPChanging)();
	bool allow;

public:
	explicit iNotifyPropertyChanging(bool act = false, void (*func)() = nullptr) : active{act}, functionNPChanging{func} {}

	void AddNPChangingListener() {
		active = true;
	}

	void RemoveNPChangingListener() {
		active = false;
	}

	bool NPChangingisActive() {
		return active;
	}

	virtual ~iNotifyPropertyChanging() = default;

	virtual void OnPropertyChanging(void (*f)(), bool *allowed) = 0;
};
