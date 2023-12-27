#pragma once

#include <string>

using std::string;

class iNotifyPropertyChanging {
private:
	bool active;

protected:
	bool (*functionNPChanging)(const string&, int, int);
	bool allow;

public:
	explicit iNotifyPropertyChanging(bool act = false, bool (*func)(const string&, int, int) = nullptr) : active{act}, functionNPChanging{func} {}

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

	virtual void OnPropertyChanging(bool (*f)(const string&, int, int)) = 0;
};
