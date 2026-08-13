object casa{
    var viveres = 50 // por ciento
    var montoReparaciones = 0
    var cuenta = cuentaCombinada
    var estrategia = full

    method estrategia() = estrategia
    method viveres() = viveres

    method aumentarViveres(porcentaje) {
        viveres = viveres + porcentaje
    }
    
    method montoReparaciones() = montoReparaciones
    method cuenta() = cuenta

    method tieneViveresSuficientes() = viveres > 40

    method necesitaReparaciones() = montoReparaciones > 0

    method estaEnOrden() = self.tieneViveresSuficientes() and not self.necesitaReparaciones() 

    method romper(importe) {
        montoReparaciones = montoReparaciones + importe
    }

    method reparar() {
        self.gastar(montoReparaciones)
        montoReparaciones = 0
    }

    method gastar(importe) {
        cuenta.extraer(importe)
    }

    method saldo() = cuenta.saldo()

    method mantenimiento(){
        estrategia.mantenimiento(self)
    }
}

object cuentaCorriente{
    var saldo = 0

    method saldo() = saldo

    method depositar(importe){
        saldo = saldo + importe
    }

    method extraer(importe){
        saldo = saldo - importe
    }
}

object cuentaConGastos{
    var saldo = 0
    var costoPorOperacion = 50

    method saldo() = saldo

    method depositar(importe){
        saldo = saldo + importe - costoPorOperacion
    }

    method extraer(importe){
        saldo = saldo - importe
    }

}

object cuentaCombinada{
    var primaria = cuentaConGastos
    var secundaria = cuentaCorriente

    method primaria() = primaria
    method secundaria() = secundaria

    method saldo() = primaria.saldo() + secundaria.saldo()

    method depositar(importe) {
        primaria.depositar(importe)
    }

    method extraer(importe) {
        if (primaria.saldo() >= importe) {
            primaria.extraer(importe)
            } else {
            secundaria.extraer(importe)
        }
    }
}

object minimoIndispensable{
    var calidad = 5

    method comprarViveres() {

    }
}

object full{
    const calidad = 5

    method mantenimiento(casa) {
        if (casa.estaEnOrden()) {
            casa.aumentarViveres(50)
            casa.gastar(50 * calidad)
        } else {
            casa.aumentarViveres(40)
            casa.gastar(40 * calidad)
        }

        if (casa.saldo() - casa.montoReparaciones() > 1000) {
            casa.reparar()
        }
    }
}
