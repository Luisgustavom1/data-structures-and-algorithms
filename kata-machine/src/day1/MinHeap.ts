export default class MinHeap {
    public length: number;
    private data: number[];    

    constructor() {
        this.data = [];
        this.length = 0;
    }

    insert(value: number): void {
        this.data[this.length] = value;
        this.heapifyUp(this.length);
        this.length++;
    }

    delete(): number {
        if (this.length === 0) {
            return -1;
        }

        const out = this.data[0];
        this.length--;
        if (this.length === 0) {
            this.data = [];
            return out;
        }

        this.data[0] = this.data[this.length]
        this.headpifyDown(0)
        return out
    }

    private headpifyDown(idx: number): void {
        const lIdx = this.leftChild(idx);
        const rIdx = this.rightChild(idx)

        if (idx >= this.length || lIdx >= this.length) return;

        const lV = this.data[lIdx]
        const rV = this.data[rIdx]
        const v = this.data[idx]

        if (lV > rV && v > rV) {
            this.data[idx] = rV;
            this.data[rIdx] = v;
            this.headpifyDown(rIdx)
        }

        if (rV > lV && v > lV) {
            this.data[idx] = lV;
            this.data[lIdx] = v;
            this.headpifyDown(lIdx)
        }
    }

    private heapifyUp(idx: number): void {
        if (idx === 0) return;

        const parent = this.parent(idx);
        const parentV = this.data[parent];
        const v = this.data[idx];

        if (v < parentV) {
            this.data[idx] = parentV;
            this.data[parent] = v;
            this.heapifyUp(parent)
        }
    }

    private parent(idx: number) {
        return Math.floor((idx - 1) / 2);
    }

    private leftChild(idx: number) {
        return 2 * idx + 1;
    } 
    
    private rightChild(idx: number) {
        return 2 * idx + 2;
    } 
}