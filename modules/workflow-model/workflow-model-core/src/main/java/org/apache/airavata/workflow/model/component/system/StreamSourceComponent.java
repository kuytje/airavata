/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

package org.apache.airavata.workflow.model.component.system;

import org.apache.airavata.workflow.model.component.Component;
import org.apache.airavata.workflow.model.component.system.SystemComponent;
import org.apache.airavata.workflow.model.component.system.SystemComponentDataPort;
import org.apache.airavata.workflow.model.graph.Graph;
import org.apache.airavata.workflow.model.graph.system.StreamSourceNode;

public class StreamSourceComponent extends SystemComponent {

    /**
     * The name of the input component
     */
    public static final String NAME = "Stream Source";

    private static final String DESCRIPTION = "A system component that represents an stream input parameter of a workflow.";

    private static final String PORT_NAME = "Parameter";

    /**
     * The description.
     */
    private static final String PORT_DESCRIPTION = "This port can be connected to any type.";

    private String rate;

    private String streamName;

    /**
     * Creates an InputComponent.
     */
    public StreamSourceComponent() {
        super();
        setName(NAME);
        setDescription(DESCRIPTION);

    }

    /**
     * Constructs a StreamSourceComponent.
     * 
     * @param stream
     * @param rate
     */
    public StreamSourceComponent(String stream, String rate) {
        setName(NAME + ":" + stream);
        this.streamName = stream;
        this.rate = rate;
        SystemComponentDataPort port = new SystemComponentDataPort(stream);
        port.setDescription(PORT_DESCRIPTION);
        this.outputs.add(port);
    }

    /**
     * @see org.apache.airavata.workflow.model.component.Component#createNode(org.apache.airavata.workflow.model.graph.Graph)
     */
    @Override
    public StreamSourceNode createNode(Graph graph) {
        StreamSourceNode node = new StreamSourceNode(graph);
        if (this.streamName != null) {
            node.setName(NAME + "_" + this.streamName);
        } else {
            node.setName(NAME);
        }
        node.setComponent(this);

        // Creates a unique ID for the node. This has to be after setName().
        node.createID();

        // Creates a output port
        createPorts(node);

        return node;
    }
}