# RCP - Rich Client Platform Samples and Tutorials

here is some info about JFace TreeViewer.

The Model is worked with MVC

* Viewer: TreeViewer, LabelProvider
* Model: Your own model, ContentProvider. The Objects should be Singleton
* Control: create the Model, change the Model, refresh Viewer

Create a RCP Application (for tutorials see: Vogella).

Add a view: Manifest -> Extensions -> All Extensions -> Add ( views)

give an ID, name and create a class.

At first create the Model. The Model is a tree with root and nodes.

```shell
root
\
 node
 \node
\
node
\node
\node
```

This example create a tree of hosts an commands for each host.

The root class. This object should be a singleton and have access to hostnames objects.

The hostnames object should have access to commands objects.

```
            RootNames
         /      |       \
    /           |           \
  host1       host2        host3
 /  |  \       |   \          |
c1  c2  c3    c1   c2         command1
```

create package: xxx.model

The model package will be have: RootNames, HostsNames and Commands class models.

```java
public class RootNames {
 private static RootNames root=null;
 public String name;
 public ArrayList children;

 private RootNames(String name) {
  this.name=name;
  children = new ArrayList();
  
 }
 
 public static RootNames getRootNames(String name) {
  if(root!=null)
   return root;
  RootNames r = new RootNames(name);
  root=r;
  return root;
 }

 public String toString() {
  return name;
 }
}
```

RootNames is a singleton, has only a name and children of HostsNames. For simplicity we do the access public. Thus we don't need implement setter or getter.

Then we implement following help methods in RootNames:

```java
 public void addChild(HostsNames child) {
  children.add(child);
  child.parent = this;
 }
 
 public void removeChild(HostsNames child) {
  children.remove(child);
  child.parent = null;
 }
 
 public HostsNames[] getChildren() {
  return (HostsNames[]) children.toArray(new HostsNames[children.size()]);
 }
 
 public boolean hasChildren() {
  return children.size()>0;
 }
```
* add/removeChild() add/remove a child in a list and set/unset the parent of child.
* getChildren() return an array of objects of children. Here a HostsNames array.

HostsNames:
```java
public class HostsNames {
 public String name;
 public String host;
 public RootNames parent;
 public ArrayList children;
 
 public HostsNames(String name, String host) {
  this.name = name;
  this.host = host;
  children = new ArrayList();
 }
 
 public void addChild(Commandos child) {
  children.add(child);
  child.parent = this;
 }
 
 public void removeChild(Commandos child) {
  children.remove(child);
  child.parent = null;
 }
 
 public Commandos[] getChildren() {
  return (Commandos[]) children.toArray(new Commandos[children.size()]);
 }
 
 public boolean hasChildren() {
  return children.size()>0;
 }

        public String toString() {
  return name;
 }
}
```
HostsNames: have a name, hostname, parent to root and children of Commandos. And helpers for Children.

Commandos:
```java
public class Commandos {
 public String name;
 public String commando;
 public HostsNames parent;
 
 public Commandos(String name, String commando)  {
  this.name = name;
  this.commando = commando;
 }

        public String toString() {
  return name;
 }
}
```
Commandos have name, commando and reference to HostsNames via parent.

Implement Provider:

create package xxx.provider

```java
public class ViewLabelProvider extends LabelProvider {
 
 public String getText(Object obj) {
  return obj.toString();
 }
 
 public Image getImage(Object obj) {
  String imageKey = ISharedImages.IMG_OBJ_ELEMENT;
  if (obj instanceof HostsNames)
     imageKey = ISharedImages.IMG_OBJ_FOLDER;
  return PlatformUI.getWorkbench().getSharedImages().getImage(imageKey);
 }
}
```
The Label Provider is a View in MVC. it give the name and the image of the Tree back, based on model.

Create a View Content Provider with implemented Interfaces: IStructuredContentProvider and ITreeContentProvider.

```java
public class ViewContentProvider implements IStructuredContentProvider, ITreeContentProvider {

 @Override
 public Object[] getElements(Object inputElement) {
  return null;
 }

 @Override
 public void dispose() { 
 }

 @Override
 public void inputChanged(Viewer viewer, Object oldInput, Object newInput) {
 }

 @Override
 public Object[] getChildren(Object parentElement) {
  return null;
 }

 @Override
 public Object getParent(Object element) {
  return null;
 }

 @Override
 public boolean hasChildren(Object element) {
  return false;
 }
}
```
The Content Provider is the model part of MVC. It provide how the TreeViewer can access the model.

following methods must be implemented: getElements(), getParent(), getChildren(), hasChildren().

Implementation:

```java
 @Override
 public Object[] getElements(Object parent) {
  return getChildren(parent);
 }
 @Override
 public Object[] getChildren(Object parent) {
  if (parent instanceof RootNames) {
   return ((RootNames)parent).getChildren();
  }
  if (parent instanceof HostsNames) {
   return ((HostsNames)parent).getChildren();
  }
  return new Object[0];
 }

 @Override
 public Object getParent(Object child) {
  if (child instanceof HostsNames) {
   return ((HostsNames)child).parent;
  }
  if (child instanceof Commandos) {
   return ((Commandos)child).parent;
  }
  return null;
 }

 @Override
 public boolean hasChildren(Object element) {
  if (element instanceof RootNames)
   return ((RootNames)element).hasChildren();
  if (element instanceof HostsNames)
   return ((HostsNames)element).hasChildren();
  return false;
 }
```

getElements and getChildren is here the same.

getChildren() return for RootNames or HostsNames his children list as an array. The same is do getParent() and hasChildren().

Now set the ViewPart:

```java
 private TreeViewer viewer;
 private RootNames root;
 
 @Override
 public void createPartControl(Composite parent) {
  viewer = new TreeViewer(parent, SWT.MULTI | SWT.H_SCROLL | SWT.V_SCROLL | SWT.BORDER);
  viewer.setContentProvider(new ViewContentProvider());
  viewer.setLabelProvider(new ViewLabelProvider());
  root=ModelCreator.createModel();
  viewer.setInput(root);
 }
```

Create the TreeViewer.

Set our Content and Label Provider. Call the Model Creator.

ModelCreator:

```java
public class ModelCreator {
 
 public static RootNames createModel() {
  RootNames root = RootNames.getRootNames("root");
  
  HostsNames hn = new HostsNames("localhost", "localhost");
  root.addChild(hn);
  hn.addChild(new Commandos("syslog", "syslog"));
  hn.addChild(new Commandos("top", "top -d 1"));
  
  hn = new HostsNames("134.108.68.107", "134.108.68.107");
  root.addChild(hn);
  hn.addChild(new Commandos("syslog", "syslog"));
  hn.addChild(new Commandos("top", "top -d 1"));
  
  return root;
 }
}
```

createModel() create a root with two hostnames and his commandos.

Then we must set the view in perspective

```java
String editorArea = layout.getEditorArea();
  layout.setEditorAreaVisible(false);
  
  layout.addStandaloneView(ViewPart1.ID,  false, IPageLayout.LEFT, 0.95f, editorArea);
  
  layout.getViewLayout(ViewPart1.ID).setCloseable(false);
```

to add some context to the tree (here an example with a Command:

```java
public class CommandAdd extends AbstractHandler {

 @Override
 public Object execute(ExecutionEvent event) throws ExecutionException {
  System.out.println("blub");
  RootNames root = ViewPart1.getTreeRoot();
  System.out.println("blub: "+root);
  
  HostsNames hn = new HostsNames("212.40.32.55", "212.40.32.55");
  root.addChild(hn);
  hn.addChild(new Commandos("syslog", "syslog"));
  hn.addChild(new Commandos("top", "top -d 1"));
  hn.addChild(new Commandos("network", "network"));

  ViewPart1.getTreeViewer().refresh();
  
  return null;
 }
}
```

simple get the singleton and add some childs. Then refresh the view.

here is the continuation of part one.

tutorial to JFace TreeViewer very good details.

At first we change our staticaly views and root objects.

change in ViewPart1 (thus was it called my TreeViewer ViewPart)

```java
private TreeViewer viewer;
private RootNames root;

        public RootNames getTreeRoot() {
  return root;
 }
 
 public TreeViewer getTreeViewer() {
  return viewer;
 }
```

now change the create the Command Add and Del and add them to menu. (see Vogella )

```java
public class CommandAdd extends AbstractHandler {

 @Override
 public Object execute(ExecutionEvent event) throws ExecutionException {

  System.out.println("start");
  ViewPart1 view = (ViewPart1) HandlerUtil.getActiveWorkbenchWindow(event).getActivePage().findView(ViewPart1.ID);

  RootNames root = view.getTreeRoot();
  
  HostsNames hn = new HostsNames("212.40.32.55", "212.40.32.55");
  root.addChild(hn);
  hn.addChild(new Commandos("syslog", "syslog"));
  hn.addChild(new Commandos("top", "top -d 1"));
  hn.addChild(new Commandos("network", "network"));

  view.getTreeViewer().refresh();
  return null;
 }
}
```
```java
public class CommandDel extends AbstractHandler {

 @Override
 public Object execute(ExecutionEvent event) throws ExecutionException {
  
  ViewPart1 view = (ViewPart1) HandlerUtil.getActiveWorkbenchWindow(event).getActivePage().findView(ViewPart1.ID);
  
  RootNames root = view.getTreeRoot();
  
  HostsNames hn = root.getChildren()[0];
  
  Commandos c = hn.children.get(0);
  
  hn.removeChild(c);
  
  view.getTreeViewer().refresh();
  return null;
 }

}
```

Now we create a second View where we simple put some text.

The commands simple add and del some item of tree.

```java
public class OutputView extends ViewPart {
 public static final String ID = "zzz.zmytest.Tree.Views.OutputView";
 public Text text;
 
 @Override
 public void createPartControl(Composite parent) {
  text = new Text(parent, SWT.BORDER);
  text.setText("Imagine a fantastic user interface here");
 }

 @Override
 public void setFocus() {
 }
}
```

we will simple alter the text.

selection Listener

selection Listener

we implement ISelectionListener:

```java
public class OutputView extends ViewPart implements  ISelectionListener{

 @Override
 public void createPartControl(Composite parent) {
  ...

  getSite().getPage().addSelectionListener((ISelectionListener) this);
 }

 @Override
 public void selectionChanged(IWorkbenchPart part, ISelection selection) {
  text.setText(selection.toString());
 }
}
```

add the view in the perspective:

```java
public class Perspective implements IPerspectiveFactory {

 public void createInitialLayout(IPageLayout layout) {
  String editorArea = layout.getEditorArea();
  layout.setEditorAreaVisible(false);
  
  layout.addStandaloneView(ViewPart1.ID,  false, IPageLayout.LEFT, 0.25f, editorArea);
  IFolderLayout folder = layout.createFolder("outputs", IPageLayout.TOP, 0.5f, editorArea);
  folder.addPlaceholder(OutputView.ID + ":*");
  folder.addView(OutputView.ID);
  
  layout.getViewLayout(ViewPart1.ID).setCloseable(false);
 }
}
```

set the tree view to selection provider:

```java
public class ViewPart1 extends ViewPart {
 ...

 public void createPartControl(Composite parent) {
  ...

  // add to selection provider
  getSite().setSelectionProvider(viewer);

 }
```
improve the listener:

```java
 @Override
 public void selectionChanged(IWorkbenchPart part, ISelection selection) {
  if (selection instanceof IStructuredSelection) {
   Object obj = ((IStructuredSelection) selection).getFirstElement();
   if (obj != null) {
    if (obj instanceof HostsNames) {
     HostsNames hn = (HostsNames)obj;
     text.setText("hostname: "+hn.name);
    } else if (obj instanceof Commandos) {
     Commandos co = (Commandos)obj;
     HostsNames hn = co.parent;
     text.setText("commando: "+co.name+ " von host: "+hn.name);
    }
   }
  }
 }
```

the listener look for IStructuredSelection, get the object and test the object for our class instances.

Now we can add further views provider and listener without to handle the wired code.s

Eclipse Forms allow you to achieve the Web look. Eclipse Editors for Manifest files (f.e) are coded in Forms.

tutorials links:

vogella tutorial about forms

forms tutorial 2

forms tutorial 3

Forms use Views:

```java
public class FormView extends ViewPart {
public void createPartControl(Composite parent) {
  toolkit = new FormToolkit(parent.getDisplay());
  form = toolkit.createForm(parent);
  form.setText("Hello, Eclipse Forms");

it create the form where you can set other widgets.

Therefore forms use GridLayot, GridData, Buttons and other similar as SWT.


 GridLayout layout = new GridLayout();
 form.getBody().setLayout(layout);

 layout.numColumns = 2;
 GridData gd = new GridData();
 gd.horizontalSpan = 2;
 link.setLayoutData(gd);
 Label label = new Label(form.getBody(), SWT.NULL);
 label.setText("Text field label:");
 Text text = new Text(form.getBody(), SWT.BORDER);
 text.setLayoutData(new GridData(GridData.FILL_HORIZONTAL));
 Button button = new Button(form.getBody(), SWT.CHECK);
 button.setText("An example of a checkbox in a form");
 gd = new GridData();
 gd.horizontalSpan = 2;
 button.setLayoutData(gd);


 Hyperlink link = toolkit.createHyperlink(form.getBody(), "Click here.", SWT.WRAP);
 link.addHyperlinkListener(new HyperlinkAdapter() {
   public void linkActivated(HyperlinkEvent e) {
     System.out.println("Link activated!");
   }
 });
```

create a hyperlink as a HTML hyperlink.

for more information look tutorials

