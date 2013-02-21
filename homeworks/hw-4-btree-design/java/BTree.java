/**
 * BTree.java
 *
 * This is the data structure and interface definition for
 * B-Trees. You shouldn't edit this file. Instead sub-class it in the
 * BTreeImpl.java file and override the abstract methods. You may also
 * create your own constructor if you like.
 **/
public abstract class BTree {

    protected int numKeys;
    protected int[] keys;
    protected boolean isLeaf;
    protected BTree[] children;

    public BTree(int order) {
	numKeys = 0;
	keys = new int[order-1];
	isLeaf = false;
	children = new BTree[order];
    }

    /**
     * Public accessor to get the number of valid keys. This implies
     * there are numKeys + 1 valid children unless this is a leaf.
     **/
    public final int getNumKeys() {
	return numKeys;
    }

    /**
     * Gives the key array. See getNumKeys() for restrictions.
     **/
    public final int[] getKeys() {
	return keys;
    }

    /**
     * Tells you if this is a leaf node. Leaf nodes are not allowed to
     * contain children when an operation finishes.
     **/
    public final boolean isLeaf() {
	return isLeaf;
    }

    /**
     * Gives the child array. See getNumKeys() and isLeaf() for
     * restrictions.
     **/
    public final BTree[] getChildren() {
	return children;
    }

    /**
     * -------------------------------------------- I N S E R T ---------
     *
     * Insert the given key into a b-tree rooted at 'root'.  If the
     * key is already contained in the btree this should do nothing.
     * 
     * On exit: 
     * -- the 'root' member should refer to the root of the
     *    tree. (the root may change when we insert or delete)
     * -- the btree referred to by 'root' is valid.
     **/
    abstract void insert(BTreeRoot root, int key);

    /**
     * -------------------------------------------- R E M O V E ---------
     *
     * Remove the given key from a b-tree rooted at 'root'. If the key is
     * not in the btree this should do nothing.
     *
     * On exit:
     * -- the 'root' pointer should refer to the root of the
     *    tree. (the root may change when we insert or delete)
     * -- the btree pointed to by 'root' is valid.
     **/
    abstract void remove(BTreeRoot root, int key);

    /**
     * ----------------------------------------- C O N T A I N S --------
     *
     * Return true if any node accessed from the given root node contains
     * the provided key value.
     **/
    abstract boolean contains(BTreeRoot root, int key);

}

