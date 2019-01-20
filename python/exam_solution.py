import datetime

class PostcardList():
    
    def __init__(self):
        
        self._file = None
        self._postcards = []
        self._date = {}
        self._from = {}
        self._to = {}
        
    def readFile(self, from_file_name):
        self._file = from_file_name
        with open(from_file_name, 'r') as file:
            for line in file:
                self._postcards.append(line)
                
            self.parsePostcards()
            
    def writeFile(self, to_file_name):
        with open(to_file_name, 'w') as file:
            for line in self._postcards:
                file.write(line)
                
    def updateFile(self, new_postcards):
        with open(self._file, 'a+') as file:
            for line in new_postcards:
                file.write(line)
                
    def updateLists(self, from_file_name):
        new_postcard = []
        with open(from_file_name, 'r') as file:
            for line in file:  
                self._postcards.append(line)
                new_postcard.append(line)
                
            self.parsePostcards()
            self.updateFile(new_postcard)

    def parsePostcards(self):
        dates = []
        senders = []
        receivers = []
        
        for postcard in self._postcards:
            dates.append((postcard.split(";")[0]).split(":")[1])
            senders.append((postcard.split(";")[1]).split(":")[1])
            receivers.append((postcard.split(";")[2]).split(":")[1])
                
        for i, date in enumerate(dates, 0):
                if date not in self._date.keys():
                    self._date[date] = [i]
                else:
                    self._date[date].append(i)
                    
        for i, sender in enumerate(senders, 0):
                if sender not in self._from.keys():
                    self._from[sender] = [i]
                else:
                    self._from[sender].append(i)
                    
        for i, receiver in enumerate(receivers, 0):
                if receiver not in self._to.keys():
                    self._to[receiver] = [i]
                else:
                    self._to[receiver].append(i)
     
    def getNumberOfPostcards(self):
        return len(self._postcards)
    
    def getPostcardsByDateRange(self, date_range): 
        min_range = date_range[0]
        max_range = date_range[1]
        
        postcard_inrange = []
        for postcard in self._postcards:
            date = (postcard.split(";")[0]).split(":")[1]
            tmp = datetime.datetime.strptime(date, "%Y-%m-%d")
            if tmp >= min_range and tmp <= max_range:
                postcard_inrange.append(postcard)
            
        return postcard_inrange

    def getPostcardsBySender(self, sender):
        postcards_from_sender = []
        for postcard in self._postcards: 
            if sender == (postcard.split(";")[1]).split(":")[1]:
                postcards_from_sender.append(postcard)
        return postcards_from_sender
    
    def getPostcardsByReceiver(self, receiver):
        return [postcard for postcard in self._postcards if receiver == (postcard.split(";")[2]).split(":")[1]]
