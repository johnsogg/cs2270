public class BTreeRoot {

    /**
     * The order of the tree refers the maximum number of children it
     * is allowed to have. See the invariants document for details.
     **/
    public final int BTREE_ORDER;

    public BTreeRoot(int order) {
	BTREE_ORDER = order;
    }

    protected BTree topNode;

    public BTree getTopNode() {
	return topNode;
    }

    public boolean isEmpty() {
	return topNode == null;
    }

    public void setTopNode(BTree newTop) {
	topNode = newTop;
    }
}
