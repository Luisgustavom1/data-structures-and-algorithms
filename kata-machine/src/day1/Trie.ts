export class Trie {
    private childNodes: Array<Trie> = Array(26);
    public isEndWord: boolean = false;

    constructor() {}

    insert(word: string): void {
        let curr: Trie = this;
        
        for (const c of word) {
            if (!curr.lookup(c)) {
                const newNode = new Trie();
                curr.childNodes[curr.indexed(c)] = newNode;
            }

            curr = curr.lookup(c);
        }

        curr.isEndWord = true;
    }

    search(word: string): boolean {
        let curr: Trie = this;

        for (const c of word) {
            if (!curr) return false;
            curr = curr.lookup(c);
        }

        return curr.isEndWord;
    }

    startsWith(prefix: string): boolean {
        let curr: Trie = this;

        for (const c of prefix) {
            if (!curr) return false;
            curr = curr.lookup(c);
        }

        return true;
    }

    find(prefix: string): Array<string> {
        let curr: Trie = this;
        for (const c of prefix) {
            curr = curr.lookup(c);
        }
        const result: Array<string> = [];
        this.findWords(curr, prefix, result);
        return result
    }

    delete(word: string): void {
        let curr: Trie = this;
        for (const c of word) {
            curr = curr.lookup(c);
        }
        if (!curr.isEndWord) return;
        curr.isEndWord = false;
    }

    findWords(curr: Trie, prefix: string, result: Array<string>) {
        if (curr.isEndWord) {
            result.push(prefix);
        }

        for (let i = 0; i < curr.childNodes.length; i++) {
            const trie = curr.childNodes[i];
            if (trie) {
                this.findWords(trie, prefix + String.fromCharCode(i + 97), result);
            }
        }
    }

    lookup(char: string): Trie {
        return this.childNodes[this.indexed(char)]
    }

    indexed(char: string): number {
        return char.charCodeAt(0) - 97;
    }    
}
