#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
    void publicMethod() {
        cout << "Base public method" << endl;
    }

protected:
    int protectedVar;
    void protectedMethod() {
        cout << "Base protected method" << endl;
    }

private:
    int privateVar;
    void privateMethod() {
        cout << "Base private method" << endl;
    }
};

class PublicDerived : public Base {
public:
    void testAccess() {
        cout << "--- Public Inheritance ---" << endl;
        
        // Public members of Base
        publicVar = 1;            // Accessible - public in derived
        publicMethod();           // Accessible - public in derived
        
        // Protected members of Base
        protectedVar = 2;         // Accessible - protected in derived
        protectedMethod();        // Accessible - protected in derived
        
        // Private members of Base
        // privateVar = 3;        // Not accessible - private remains private
        // privateMethod();       // Not accessible - private remains private
        
        cout << endl;
    }
};

// Private inheritance
class PrivateDerived : private Base {
public:
    void testAccess() {
        cout << "--- Private Inheritance ---" << endl;
        
        // Public members of Base
        publicVar = 1;            // Accessible - private in derived
        publicMethod();           // Accessible - private in derived
        
        // Protected members of Base
        protectedVar = 2;         // Accessible - private in derived
        protectedMethod();        // Accessible - private in derived
        
        // Private members of Base
        // privateVar = 3;        // Not accessible - private remains private
        // privateMethod();       // Not accessible - private remains private
        
        cout << endl;
    }
    
    // Expose some methods to show outside access
    void exposedPublicMethod() {
        publicMethod();  // We can access this inside
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
public:
    void testAccess() {
        cout << "--- Protected Inheritance ---" << endl;
        
        // Public members of Base
        publicVar = 1;            // Accessible - protected in derived
        publicMethod();           // Accessible - protected in derived
        
        // Protected members of Base
        protectedVar = 2;         // Accessible - protected in derived
        protectedMethod();        // Accessible - protected in derived
        
        // Private members of Base
        // privateVar = 3;        // Not accessible - private remains private
        // privateMethod();       // Not accessible - private remains private
        
        cout << endl;
    }
};

// Testing further inheritance
class FurtherDerived : public PublicDerived {
public:
    void testFurtherAccess() {
        cout << "--- Further Inheritance from Public Derived ---" << endl;
        
        // Public members of Base
        publicVar = 1;            // Accessible - public in PublicDerived
        publicMethod();           // Accessible - public in PublicDerived
        
        // Protected members of Base
        protectedVar = 2;         // Accessible - protected in PublicDerived
        protectedMethod();        // Accessible - protected in PublicDerived
        
        // Private members of Base - not accessible
        
        cout << endl;
    }
};

class FurtherDerivedFromPrivate : public PrivateDerived {
public:
    void testFurtherAccess() {
        cout << "--- Further Inheritance from Private Derived ---" << endl;
        
        // All Base members become private in PrivateDerived and are not accessible
        // publicVar = 1;            // Not accessible
        // publicMethod();           // Not accessible
        // protectedVar = 2;         // Not accessible
        // protectedMethod();        // Not accessible
        
        exposedPublicMethod();    // Only explicitly exposed methods are accessible
        
        cout << endl;
    }
};

class FurtherDerivedFromProtected : public ProtectedDerived {
public:
    void testFurtherAccess() {
        cout << "--- Further Inheritance from Protected Derived ---" << endl;
        
        // Public members of Base become protected in ProtectedDerived
        publicVar = 1;            // Accessible - protected in ProtectedDerived  
        publicMethod();           // Accessible - protected in ProtectedDerived
        
        // Protected members of Base remain protected in ProtectedDerived
        protectedVar = 2;         // Accessible - protected in ProtectedDerived
        protectedMethod();        // Accessible - protected in ProtectedDerived
        
        cout << endl;
    }
};

int main() {
    Base baseObj;
    PublicDerived publicDerived;
    PrivateDerived privateDerived;
    ProtectedDerived protectedDerived;
    FurtherDerived furtherDerived;
    FurtherDerivedFromPrivate furtherPrivate;
    FurtherDerivedFromProtected furtherProtected;
    
    cout << "Testing access within derived classes:" << endl;
    publicDerived.testAccess();
    privateDerived.testAccess();
    protectedDerived.testAccess();
    furtherDerived.testFurtherAccess();
    furtherPrivate.testFurtherAccess();
    furtherProtected.testFurtherAccess();
    
    cout << "Testing access from outside:" << endl;
    
    // Access from Base object
    baseObj.publicVar = 10;       // Accessible
    baseObj.publicMethod();       // Accessible
    // baseObj.protectedVar = 20; // Not accessible from outside
    // baseObj.protectedMethod(); // Not accessible from outside
    // baseObj.privateVar = 30;   // Not accessible from outside
    // baseObj.privateMethod();   // Not accessible from outside
    
    // Access from PublicDerived
    publicDerived.publicVar = 10;       // Accessible - public inheritance preserves public
    publicDerived.publicMethod();       // Accessible - public inheritance preserves public
    // publicDerived.protectedVar = 20; // Not accessible from outside
    // publicDerived.protectedMethod(); // Not accessible from outside
    
    // Access from PrivateDerived
    // privateDerived.publicVar = 10;       // Not accessible - private inheritance hides all
    // privateDerived.publicMethod();       // Not accessible - private inheritance hides all
    privateDerived.exposedPublicMethod();   // Only explicitly exposed methods are accessible
    
    // Access from ProtectedDerived
    // protectedDerived.publicVar = 10;     
    // protectedDerived.publicMethod();     
    
    return 0;
}