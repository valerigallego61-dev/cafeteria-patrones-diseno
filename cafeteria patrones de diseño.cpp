#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// ==========================================
// 3. PATR�N DE COMPORTAMIENTO: Observer
// ==========================================
class IObserver {
public:
	virtual void actualizar(const string& estado) = 0;
	virtual ~IObserver() = default;
};

class Cliente : public IObserver {
private:
	string nombre;
public:
	Cliente(string n) : nombre(n) {}
	void actualizar(const string& estado) override {
		cout << "[Notificacion para " << nombre << "]: Tu pedido ahora esta " << estado << endl;
	}
};

class SujetoPedido {
private:
	vector<shared_ptr<IObserver>> observadores;
	string estado;
public:
	void agregarObservador(shared_ptr<IObserver> obs) {
		observadores.push_back(obs);
	}
	void setEstado(string nuevoEstado) {
		estado = nuevoEstado;
		for (auto& obs : observadores) {
			obs->actualizar(estado);
		}
	}
};

// ==========================================
// INTERFAZ BASE PARA BEBIDAS
// ==========================================
class Bebida {
public:
	virtual string getDescripcion() const = 0;
	virtual double costo() const = 0;
	virtual ~Bebida() = default;
};

// Bebidas concretas
class CafeEspresso : public Bebida {
public:
	string getDescripcion() const override { return "Cafe Espresso"; }
	double costo() const override { return 5.00; }
};

class TeNegro : public Bebida {
public:
	string getDescripcion() const override { return "Te Negro"; }
	double costo() const override { return 4.00; }
};

// ==========================================
// 1. PATR�N CREACIONAL: Factory Method
// ==========================================
class CafeteriaFactory {
public:
	static unique_ptr<Bebida> crearBebida(const string& tipo) {
		if (tipo == "espresso") return make_unique<CafeEspresso>();
		if (tipo == "te") return make_unique<TeNegro>();
		return nullptr;
	}
};

// ==========================================
// 2. PATR�N ESTRUCTURAL: Decorator
// ==========================================
class BebidaDecorador : public Bebida {
protected:
	unique_ptr<Bebida> bebida;
public:
	BebidaDecorador(unique_ptr<Bebida> b) : bebida(move(b)) {}
};

class ConLeche : public BebidaDecorador {
public:
	ConLeche(unique_ptr<Bebida> b) : BebidaDecorador(move(b)) {}
	string getDescripcion() const override {
		return bebida->getDescripcion() + ", con Leche Deslactosada";
	}
	double costo() const override {
		return bebida->costo() + 1.50;
	}
};

class ConExtraShot : public BebidaDecorador {
public:
	ConExtraShot(unique_ptr<Bebida> b) : BebidaDecorador(move(b)) {}
	string getDescripcion() const override {
		return bebida->getDescripcion() + ", con Extra Shot de Cafe";
	}
	double costo() const override {
		return bebida->costo() + 2.00;
	}
};

// ==========================================
// FLUJO PRINCIPAL DE LA APLICACI�N
// ==========================================
int main() {
	cout << "=== SISTEMA DE GESTION DE CAFETERIA ===" << endl;
	
	// Configurar el sistema de notificaciones (Observer)
	SujetoPedido pedidoActual;
	auto cliente = make_shared<Cliente>("Carlos");
	pedidoActual.agregarObservador(cliente);
	
	// 1. CREACIONAL: Factory Method crea la bebida base
	cout << "\n[1] Creando bebida base..." << endl;
	unique_ptr<Bebida> miBebida = CafeteriaFactory::crearBebida("espresso");
	
	// 2. ESTRUCTURAL: Decorator envuelve la bebida agregando extras din�micos
	cout << "[2] Agregando modificadores (Decorador)..." << endl;
	miBebida = make_unique<ConLeche>(move(miBebida));
	miBebida = make_unique<ConExtraShot>(move(miBebida));
	
	cout << "Detalle final: " << miBebida->getDescripcion() << endl;
	cout << "Costo total: $" << miBebida->costo() << endl;
	
	// 3. COMPORTAMIENTO: Observer avisa los cambios del pedido
	cout << "\n[3] Iniciando proceso de preparacion (Observer)..." << endl;
	pedidoActual.setEstado("En preparacion");
	pedidoActual.setEstado("Listo para retirar en barra");
	
	return 0;
}
