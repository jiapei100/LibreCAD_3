#ifndef ENTITYMANAGERIMPL_H
#define ENTITYMANAGERIMPL_H

#include "cad/const.h"

#include "cad/document/document.h"
#include "cad/document/storagemanager.h"
#include "cad/events/addentityevent.h"
#include "cad/events/addlayerevent.h"
#include "cad/events/removelayerevent.h"
#include "cad/events/replacelayerevent.h"
#include "cad/events/removeentityevent.h"
#include "entitycontainer.h"

#include <cad/events/replaceentityevent.h>

namespace lc {
    /**
     * A default storag emanager for document's.
     * The data will be cerated in memory and will be lost when the application terminates
     *
     * @param document
     */
    class StorageManagerImpl : public StorageManager {
            Q_OBJECT
        public:
            /*!
             * \brief Entity manager implementor.
             * \param document
             */
            StorageManagerImpl();

        public:
            virtual void insertEntity(const shared_ptr<const CADEntity>);
            virtual void insertEntityContainer(const EntityContainer&);
            virtual void removeEntity(const shared_ptr<const CADEntity>);
            virtual shared_ptr<const CADEntity> entityByID(const ID_DATATYPE id) const;
            virtual EntityContainer entitiesByLayer(const shared_ptr<const Layer> layer) const;

            virtual shared_ptr<const Layer> layerByName(const QString& layerName) const;
            virtual QHash <QString, shared_ptr<const Layer> > const& allLayers() const;

        private:
            EntityContainer _entities;
            QHash <QString, shared_ptr<const Layer> > _layers;
    };
}
#endif // ENTITYMANAGERIMPL_H
