#pragma once
#include "HitBoxComponent.h"
#include "Singleton.h"

namespace dae
{
	//keep a list of pointers to all the hitboxes, does/should not delete them
	class HitBoxManager final : public Singleton<HitBoxManager>
	{
	public:
		void Update() {};
		void Render() {};
		void addHitBox(HitBoxComponent* toAdd) { nm_pHitBoxes.push_back(toAdd); };
		
		const std::vector<HitBoxComponent*>& GetAllHitBoxes() { return nm_pHitBoxes; }
	
	private:
		
		friend class Singleton<HitBoxManager>;
		HitBoxManager() = default;
		
		std::vector<HitBoxComponent*> nm_pHitBoxes;

	};
}

