function PriorityQueue() {
    var collection = [];
    this.printCollection = function() {
        (console.log(collection));
    };
    this.enqueue = function(element) {
        if(this.isEmpty()) {
            collection.push(element);
        } else {
            var added = false;
            for (var i = 0; i < collection.length; i++) {
                if(element[i] < collection[i][i]) { // checking priorities
                    collection.splice(i, 0, element);
                    added = true;
                    break;
                }
            }
            if(!added) {
                collection.push(element);
            }
        }
    };
    this.dequeue = function() {
        var value = collection.shift();
        return value[0];
    };
    this.front = function() {
        return collection[0];
    };
    this.size = function() {
        return collection.length;
    };
    this.isEmpty = function() {
        return (collection.length === 0);
    };
}

var pq = new PriorityQueue();
pq.enqueue(['Beau Caranes', 2]);
pq.enqueue(['Quincy Larson', 3]);
pq.enqueue(['Ewa Mitulska-Wójcik', 1]);
pq.printCollection();
pq.dequeue();
pq.front();
pq.printCollection();