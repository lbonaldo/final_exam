import datetime

class PostcardList():
    
    def __init__(self): 
        self._file = str()
        self._postcards = []
        self._date = {}
        self._from = {}
        self._to = {}
        
    def readFile(self, from_file_name):
    # from self._file read self.{_date,_from,_to}    
        self.__init__()
        self.updateLists(from_file_name)
            
    def writeFile(self):
    # write self.{_date,_from,_to} to self._file  
        f = open(self._file,"w")
        f.close()
        self.updateFile()
        

    def updateFile(self):
    # updateFile(self,...): as write but appending to self._file 
        with open(self._file, 'a+') as file:
            for line in self._postcards:
                file.write(line)
                
    def updateLists(self, from_file_name):
    # as read but appending to self._postcards 
        self._file=from_file_name
        with open(from_file_name, 'r') as file:
            for line in file:  
                n = self.getNumberOfPostcards()
                self._postcards.append(line) 
                d,s,r=self.parsePostcards(line)
                self._add_record(self._date,d,n)
                self._add_record(self._from,s,n)
                self._add_record(self._to,r,n)
                
            
    def _add_record(self,Dic,Str,Ind):
        if not Str in Dic:
            Dic[Str]=list()     
        Dic[Str].append(Ind)

    def parsePostcards(self,PC):
    # parse self._postcards, set self.{_date,_from,_to} 
        date,alice,bob=PC.split()
        date=date.split(":")[1].split(";")[0]
        alice=alice.split(":")[1].split(";")[0]
        bob=bob.split(":")[1].split(";")[0]
        
        return (date,alice,bob)

    def getNumberOfPostcards(self):
    # returns length of self._postcards
        return len(self._postcards)
    
    def getPostcardsByDateRange(self, date_range): 
    # returns the postcards within a date_range
        min_range = date_range[0]
        max_range = date_range[1]
        
        postcard_inrange = []
        for d in self._date:
            tmp = datetime.datetime.strptime(d, "%Y-%m-%d")
            if tmp >= min_range and tmp <= max_range:
                postcard_inrange +=[self._postcards[i] for i in self._date[d]]
            
        return postcard_inrange

    def getPostcardsBySender(self, sender):
        # returns the postcards from a sender
        pc = []
        if sender in self._from: 
            pc = [self._postcards[i] for i in self._from[sender]]
        return pc
    
    def getPostcardsByReceiver(self, receiver):
        # returns the postcards to a receiver
        pc = []
        if receiver in self._to: 
            pc = [self._postcards[i] for i in self._to[receiver]]
        return pc
        
