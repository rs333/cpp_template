#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine {
public:
	Engine();
	int a() { return a_; }
	void a(int in) { this->a_ = in; }

private:
	int a_;

};


#endif // _ENGINE_H_