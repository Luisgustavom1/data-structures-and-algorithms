export default class ArrayList<T> {
    public length: number;
    private capacity: number;
    private arrayList: Array<T>;

    constructor(capacity: number) {
        this.length = 0;
        this.capacity = capacity;
        this.arrayList = Array(this.capacity);
    }

    prepend(item: T): void {
        this.length++;
        for (let i = this.length - 1; i > 0; i--) {
            this.arrayList[i] = this.arrayList[i - 1];
        }
        this.arrayList[0] = item;
    }

    insertAt(item: T, idx: number): void {
        this.length++;
        for (let i = this.length - 1; i > idx; i--) {
            this.arrayList[i] = this.arrayList[i - 1];
        }
        this.arrayList[idx] = item;
    }

    append(item: T): void {
        this.length++;

        if (this.length > this.capacity) {
            this.capacity *= 2;
            const tmp = this.arrayList;
            this.arrayList = Array(this.capacity);
            this.arrayList = this.arrayList.concat(tmp);
        }

        this.arrayList[this.length - 1] = item;
    }

    remove(item: T): T | undefined {
        for (let i = 0; i < this.length; i++) {
            if (this.arrayList[i] === item) {
                return this.removeAt(i);
            }
        }
        return undefined;
    }

    get(idx: number): T | undefined {
        return this.arrayList[idx];
    }

    removeAt(idx: number): T | undefined {
        const el = this.arrayList[idx];
        for (let i = idx; i < this.length; i++) {
            this.arrayList[i] = this.arrayList[i + 1];
        }
        this.length--;
        return el;
    }

    isEmpty(): boolean {
        return this.length === 0;
    }
}