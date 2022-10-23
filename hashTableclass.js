class HashTable{
    constructor(){
        this.hashTable = new Array(255);
        this.tableSize = 0
    }

    set(key,val){
       const index = this._hash(key);
       this.hashTable[index] = [key,val];
       this.tableSize++;
    }
    get(key){
      const index = this._hash(key);
      return this.hashTable[index];
    }
    remove(key){
        const index = this._hash(key);
        if(this.hashTable[index] && this.hashTable.length){
            this.hashTable[index]=[];
            return "removed";
        }else{
            return "key not avaliable"
        }
    }
    _hash(key){
        let hash = 0;
        for(let i=0;i<key.length;i++){
           hash+=key[i].charCodeAt(); 
        }
        return hash % this.hashTable.length;
    }
}

const table = new HashTable()
table.set('vishal',56);
table.set('dinesh',4545);
console.log(table.get('vishal'))
