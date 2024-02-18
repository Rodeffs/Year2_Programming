#pragma once

class iNotifyCollectionChanged {
private:
	bool active;

protected:
	void (*functionNCC)();

public:
	explicit iNotifyCollectionChanged(bool act, void (*func)()) : active{act}, functionNCC{func} {}

	void AddNCCListener() {
		active = true;
	}

	void RemoveNCCListener() {
		active = false;
	}

	bool NCCisActive() {
		return active;
	}

	virtual ~iNotifyCollectionChanged() = default;  // нужно ещё указать деструкторы

	virtual void OnCollectionChanged(void (*f)()) = 0;
};
