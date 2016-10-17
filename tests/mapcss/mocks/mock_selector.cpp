
#include "settings.hpp"
#include "server/selectors/selector.hpp"
#include "server/tile_identifier.hpp"
#include "server/render_attributes.hpp"
#include <gmock/gmock.h>

class MockSelector : public Selector {
public:
	MockSelector(shared_ptr<Rule> rule) : Selector(rule, shared_ptr<Selector>()) {}
	virtual ~MockSelector() = default;

	MOCK_CONST_METHOD3(matchNode, void(NodeId nodeID, const shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes));
	MOCK_CONST_METHOD3(matchWay, void(WayId wayID, const shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes));
	MOCK_CONST_METHOD3(matchRelation, void(RelId relID, const shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes));
};
