#pragma once
class BaseComponent
{
public:
	BaseComponent() = default;
	virtual ~BaseComponent() {};
	virtual void Update( const float deltatime) = 0;
	virtual void Render() const = 0;


	//BaseComponent(const BaseComponent& other) = delete;
	//BaseComponent(BaseComponent&& other) = delete;
	//BaseComponent& operator=(const BaseComponent& other) = delete;
	//BaseComponent& operator=(BaseComponent&& other) = delete;
private:
};

