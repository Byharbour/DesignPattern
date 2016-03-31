#新添检查规则
建议使用const变量来代替常数

#进行此开发前的分析成果
cppcheck在进行检查时有如下步骤

* 遍历所有已注册的检查类的对象。
* 调用该对象的runCheck方法进行检查。
* 将tokenlist进行简化。
* 再次遍历所有检查类的对象。
* 调用该对象的runSimplifiedCheck方法进行检查。

所以，如果我们要新添检查类的话，需要重点实现runCheck和runSimplifiedCheck这两个方法。同时还要知道如何注册该检查类的对象。

在这个检查规则中，简化后的代码会对检查造成干扰，所以我们应该在简化前就进行检查，从上述的cppcheck的检查流程可以看出，我们需要将检查功能实现在runCheck方法中。而runSimplifiedCheck方法对这个检查来说没有用处。

还有要注意的地方是Check类中有两个构造函数，用于不同的场景。

Check(const std::string &aname)用于对象的注册，所谓注册就是把对象insert到一个list中，这个list声明在Check类中。

Check(const std::string &aname, const Tokenizer * tokenizer, const Settings * settings, ErrorLogger * errorLogger)创建一个用于检查的对象。

#开发过程
新建一个检查类，类名是CheckConstNumber，继承自Check类。

新建文件checkconstnumber.cpp和checkconstnumber.hpp。

在该类中我们实现了下列函数

* CheckConstNumber()
* CheckConstNumber(const Tokenizer * tokenizer, const Settings * settings, ErrorLogger *errorLogger)
* void runChecks(const Tokenizer * , const Settings * , ErrorLogger *)
* void runSimplifiedChecks (const Tokenizer * tokenizer, const Settings * settings, ErrorLogger * errorLogger)
* void constNumber()
* void getErrorMessages(ErrorLogger * errorLogger, const Settings * settings) const
* std::string classInfo() const
* static std::string myName()

##CheckConstNumber()
该构造函数用于注册该检查类的对象，直接通过该构造函数定义一个对象即可完成注册。

```
CheckConstNumber(): Check(myName()){}
```

##CheckConstNumber(const Tokenizer * tokenizer, const Settings * settings, ErrorLogger * errorLogger)
在进行检查时通过该构造函数创建一个对象，通过该对象来调用方法。

```
CheckConstNumber(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger): Check(myName(), tokenizer, settings, errorLogger){}
```

##void runChecks(const Tokenizer * , const Settings * , ErrorLogger *)

这个方法将父类Check的该方法进行重写。主要目的是实现检查功能。先创建一个对象，再通过该对象调用constNumber方法进行检查。

```
void CheckConstNumber:: runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger){
    CheckConstNumber checkConstNumber(tokenizer, settings, errorLogger);
    checkConstNumber.constNumber();
}
```

##void runSimplifiedChecks(const Tokenizer * tokenizer, const Settings * settings, ErrorLogger * errorLogger)

这个函数在这里没用，但是因为这是Check类中的纯虚函数，所以在这里必须得进行定义。

##void constNumber()
这个函数进行对常数的检查，如果检查到常数则给出提醒。

```
void CheckConstNumber:: constNumber(){
    for(const Token *tok = _tokenizer->tokens(); tok; tok = tok->next()){
        if(Token::Match(tok, "const %type% %var% = %num% ;")){
            tok = tok->tokAt(5);
            continue;
        }
        if(Token::Match(tok, "%op%|%comp% %num%")){
            //std::cout << "Suggest use const variable to replace the const number." <<  std::endl;
            reportError(tok, Severity::warning, "const number", "Suggest use const variable to replace the const number.");
        }
        
    }
}
```

#开发中遇到的问题
在把类写完了之后不知道如何注册检查对象，当时看了很多类也没有找到怎么进行注册，后来在CheckMemoryLeak.cpp中看到了一段代码

```
// Register this check class (by creating a static instance of it)
namespace {
    CheckMemoryLeakInFunction instance1;
    CheckMemoryLeakInClass instance2;
    CheckMemoryLeakStructMember instance3;
    CheckMemoryLeakNoVar instance4;
}

```
这段代码的意思是使用匿名namespace来声明全局变量，调用的构造函数是无参数的注册构造函数。

所以使用如下代码即可注册该检查对象

```
namespace {
	CheckConstNumber checkConstNumber;
}
```