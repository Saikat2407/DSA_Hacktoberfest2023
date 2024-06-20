#importing the time module
import time
#welcoming the user
name =input("What is your name? ")
print ("Hello, " + name, "Time to play hangman!")
print("""Rules for the game are as follows:
       1. You have to guess the word. No. of_ depicts number of characters in a word.
       2. You will get 10 opportunities to guess the character.
       3. Type any alphabet after "Guess a character", if the alphabet would be present
         In the word it will be shown otherwise you lost your one opportunity""")
print()
#wait for 1 second
time.sleep(1)
print ("Start guessing...")
time.sleep(0.5)
#here we set the word
import random
nouns = ['people','history','way','art','world','information','map','two','family''government','health','system','computer','meat',
         'year','thanks','music','person','reading','method','data','food','understanding','theory','law','bird','literature','problem',
         'software','control','knowledge','power','ability','economics','love','internet','television','science','library','nature','fact',
         'product','idea','temperature','investment','area','society','activity','story','industry','media','thing','oven','community',
         'definition','safety','quality','development','language','management','player','variety','video','week','security','country',
         'exam','movie','organization','equipment','physics','analysis','policy','series','thought','basis','boyfriend','direction',
         'strategy','technology','army','camera','freedom','paper','environment','child','instance','month','truth','marketing',
         'university','writing','article','department','difference','goal','news','audience','fishing','growth','income','marriage',
         'user','combination','failure','meaning','medicine','philosophy','teacher','communication','night','chemistry','disease',
         'disk','energy','nation','road','role','soup','advertising','location','success','addition','apartment','education','math','moment',
         'painting','politics','attention','decision','event','property','shopping','student','wood','competition','distribution',
         'entertainment','office','population','president','unit','category','cigarette','context','introduction','opportunity',
         'performance','driver','flight','length','magazine','newspaper','relationship','teaching','cell','dealer','debate','finding','lake',
         'member','message','phone','scene','appearance','association','concept','customer','death','discussion','housing','inflation',
         'insurance','mood','woman','advice','blood','effort','expression','importance','opinion','payment','reality','responsibility',
         'situation','skill','statement','wealth','application','city','county','depth','estate','foundation','grandmother','heart',
         'perspective','photo','recipe','studio','topic','collection','depression','imagination','passion','percentage','resource','setting',
         'ad','agency','college','connection','criticism','debt','description','memory','patience','secretary','solution','administration',
         'aspect','attitude','director','personality','psychology','recommendation','response','selection','storage','version','alcohol',
         'argument','complaint','contract','emphasis','highway','loss','membership','possession','preparation','steak','union','agreement',
         'cancer','currency','employment','engineering','entry','interaction','limit','mixture','preference','region','republic','seat',
         'tradition','virus','actor','classroom','delivery','device','difficulty','drama','election','engine','football','guidance',
         'hotel','match','owner','priority','protection','suggestion','tension','variation','anxiety','atmosphere','awareness',
         'bread','climate','comparison','confusion','construction','elevator','emotion','employee','employer','guest','height',
         'leadership','mall','manager','operation','recording','respect','sample','transportation','boring','charity','cousin','disaster',
         'editor','efficiency','excitement','extent','feedback','guitar','homework','leader','mom','outcome','permission','presentation',
         'promotion','reflection','refrigerator','resolution','revenue','session','singer','tennis','basket','bonus','cabinet','childhood',
         'church','clothes','coffee','dinner','drawing','hair','hearing','initiative','judgment','lab','measurement','mode','mud','orange',
         'poetry','police','possibility','procedure','queen','ratio','relation','restaurant','satisfaction','sector','signature','significance',
         'song','tooth','town','vehicle','volume','wife','accident','airport','appointment','arrival','assumption','baseball','chapter',
         'committee','conversation','database','enthusiasm','error','explanation','farmer','gate','girl','hall','historian','hospital','injury',
         'instruction','maintenance','manufacturer','meal','perception','pie','poem','presence','proposal','reception','replacement','revolution',
         'river','son','speech','tea','village','warning','winner','worker','writer','assistance','breath','buyer','chest','chocolate','conclusion',
         'contribution','cookie','courage','dad','desk','drawer','establishment','examination','garbage','grocery','honey','impression','improvement',
         'independence','insect','inspection','inspector','king','ladder','menu','penalty','piano','potato','profession','professor','quantity','reaction',
         'requirement','salad','sister','supermarket','tongue','weakness','wedding','affair','ambition','analyst','apple','assignment','assistant',
         'bedroom','beer','birthday','celebration','championship','cheek','client','consequence','departure','diamond','dirt','ear','fortune','friendship',
         'gene','girlfriend','hat','indication','intention','lady','midnight','negotiation','obligation','passenger','pizza','platform','poet','pollution',
         'recognition','reputation','shirt','sir','speaker','stranger','surgery','sympathy','tale','throat','trainer','uncle','youth','time','work','film',
         'water','money','example','while','business','study','game','life','form','air','day','place','number','part','field','fish','back','process','heat',
         'hand','experience','job','book','end','point','type','home','economy','value','body','market','guide','interest','state','radio','course','company',
         'price','size','card','list','mind','trade','line','care','group','risk','word','fat','force','key','light','training','name','school','top','amount',
         'level','order','practice','research','sense','service','piece','web','boss','sport','fun','house','page','term','test','answer','sound','focus','oil',
         'matter','kind','soil','board','picture','access','garden','range','rate','reason','future','site','demand','exercise','image','case','cause','coast',
         'action','age','bad','boat','record','result','section','building','mouse','cash','class','nothing','period','plan','store','tax','side','subject',
         'space','rule','stock','weather','chance','figure','man','model','source','beginning','earth','program','chicken','design','feature','head','material',
         'purpose','question','rock','salt','act','birth','car','dog','object','scale','sun','note','profit','rent','speed','style','war','bank','craft','half',
         'inside','outside','standard','bus','exchange','eye','fire','quote','recover','resolve','roll','sink','slip','spare','suspect','sweet','swing','twist',
         'upstairs','usual','abroad','brave','calm','concentrate','estimate','grand','male','mine','prompt','quiet','refuse','regret','reveal','delay',
         'drunk','female','hurry','inevitable','invite','kiss','neat','pop','punch','quit','reply','representative','resist','rip','rub','silly','smile',
         'spell','stretch','stupid','tear','temporary','tomorrow','wake','wrap','yesterday', 'rush','shake','shift','shine','steal','suck','surround']
word=" ".join([nouns[random.randrange(0, len(nouns))] for i in range(1)])
#creates an variable with an empty value
guesses = ''
#determine the number of turns
turns = 10
# Create a while loop
#check if the turns are more than zero
while turns > 0:         
 # make a counter that starts with zero
    failed = 0             
    # for every character in word    
    for char in word:      
    # sees if the character is in the players guess
        if char in guesses:    
            # print then out the character
            print (char),    
        else:
    # if not found, print a dash
            print ("_"),     
    # and increase the failed counter with one
            failed += 1    
# if failed is equal to zero
  # print You Won
    if failed == 0:        
        print ("You won") 
        print("You correctly guessed the word:-'",word,"'")
    # exit the script
        break              
    print()
   # ask the user go guess a character
    guess = input("guess a character:") 

    # set the players guess to guesses
    guesses += guess                    

    # if the guess is not found in the secret word
    if guess not in word:  
 
     # turns counter decreases with 1 (now 9)
        turns -= 1        
 
    # print wrong
        print ("Wrong")    
 
    # how many turns are left
        print ("You have", + turns, 'more guesses')
 
    # if the turns are equal to zero
        if turns == 0:           
    
        # print "You Lose"
            print ("You Lose")  
            print("The word was,",word)
print()
