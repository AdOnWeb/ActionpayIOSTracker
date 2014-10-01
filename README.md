ActionpayIOSTracker
===================

SDK для внедрения в сторонние проекты с целью отслеживания установки приложения а также целевых действий пользователей.

Внедрение
=========

Подключение SDK
---------------

Линкуем ActionpayTracker.framework в проект.

### Необходимые Frameworks

 * Foundation.framework
 * CFNetwork.framework
 * MobileCoreServices.framework
 * Security.framework
 * SystemConfiguration.framework

### Установка из CocoaPods

```sh
pod 'ActionpayIOSTracker', '~> 1.0.1'
```

### Build config

Framework представляет из себя статическую библиотеку, поэтому необходимо добавить флаг в настройках вашего проекта.

Other Linker Fags: -all_load

### Регистрируем URL схему

В некоторых ситуациях для отслеживания установки необходима обратная связь с приложением через URL Scheme. Для првильной работы наличие URL схемы необходима.

### Затем инициализируем трэкер.

```objc

// ...

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Инициализируем параметры трэкера
  // [SLTracker initTest:@"sltestscheme" /* URL scheme */ installUrl:nil]; // Инициализация в тестовом режиме
  [SLTracker init:@"my_app_id" scheme:@"sltestscheme" installUrl:nil]; // Инициализация в боевом режиме
  // Установим время автоматической отсылки событий
  [[SLTracker sharedTracker] setUpdateInterval:10 /* каждые 10 секунд */ repeat:YES /* повторять */];
  // Начать следить за состоянием изменения подключения к интернету
  [[SLTracker sharedTracker] connectionListenerStart];
  // Установить делегат для контроля цикла обработки событий
  [[SLTracker sharedTracker] setDelegate:self];

  return YES;
}

// ЭТО НЕОБХОДИМО СДЕЛАТЬ: Устанавливаем обработчик URL Scheme
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
  return [SLTracker.sharedTracker trackUrl:application url:url];
}

#pragma mark – SmartLeadTracker delegate

- (BOOL)onBeginTrack:(id)sender action:(SLAction *)action
{
  NSLog(@"onBeginTrack: %@ action: %@", sender, action.name);
  return YES;
}

- (BOOL)onBeginSend:(id)sender action:(SLAction *)action
{
  NSLog(@"onBeginSend: %@ action: %@", sender, action.name);
  return YES;
}

- (void)onEndSend:(id)sender action:(SLAction *)action
{
  NSLog(@"onEndSend: %@ action: %@ -> %d", sender, action.name, action.sent);
}

// ...

```

Использование
-------------

Событие происходит только один раз

```objc
[[SLTracker sharedTracker] trackAction:@"event" apid:nil]; // Повторно событие не отработает
```

Событие отрабатывает каждый раз

```objc
[[SLTracker sharedTracker] trackAction:@"purchase" price:@"440" orderid:nil];
```

Методы отслеживания событий

```objc
  // name – имя события
  // price – используется при регистрации событий оплаты (если указан этот параметр событие отрабатывает каждый раз)
  // orderId – Идетификатор заказа (Используется совместно с price)
  // apid – Постфикс идентификатор (если хотите указать свой постфикс к имени события, в противном случае он будет формироваться автоматически)

- (BOOL)trackAction:(NSString *)name
              price:(NSString *)price
            orderid:(NSString *)orderid;

- (BOOL)trackAction:(NSString *)name
              price:(NSString *)price
            orderid:(NSString *)orderid
               apid:(NSString *)apid;

- (BOOL)trackAction:(NSString *)name
               apid:(NSString *)apid;

// Простое событие вызывается единожды
- (BOOL)trackAction:(NSString *)name;
```

Обратная связь
==============
